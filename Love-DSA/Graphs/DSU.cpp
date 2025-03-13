#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
DSU:disjoint set unioun , all set have different value
->there are two main funtion in DSU : union and find 
unioun for combind two set and find for find the parent of set member
*/
vector<int> parent,rank;
    
int find(int x)
{
    if(x==parent[x])
    return x;
    else
    return parent[x]=find(parent[x]); // with path compression
    //return find(parent[x])
}
void Union(int x,int y)
{
    int x_parent=find(x);
    int y_parent=find(y);
    
    if(x_parent==y_parent)
    return;
    
    if(rank[x_parent]>rank[y_parent]) // x become papa
    parent[y_parent]=x_parent;
    else if(rank[y_parent]>rank[x_parent]) // y become papa
    parent[x_parent]=y_parent;
    else
    {
        parent[x_parent]=y_parent; //anyone can be papa
        rank[y_parent]++;//here y become papa so increse y's rank by 1
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)cx
    for(int i=0;i<n;i++)
    {
        parent.push_back(i);
        rank.push_back(0);
    }
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;  
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // parent.resize(V);
    // rank.resize(V);
    // for(int i=0;i<V;i++)
    // {
    //     parent[i]=i;
    //     rank[i]=0;
    // }

    //detect cycle using DSU
    //if parent of two memeber are same so they belong to same set and they definetly have cycle 
    for(int i=0;i<V;i++)
    {
        parent.push_back(i);
        rank.push_back(0);
    }
    
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            if(i<it) // if we perform 0->1 so we don't need to perform 1->0
            {
                int x_parent=find(i);
                int y_parent=find(it);
                
                if(x_parent==y_parent)
                return 1;
                
                Union(i,it);
            }
        }
    }
    return 0;
}