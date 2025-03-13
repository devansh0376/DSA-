#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int node,vector<int> &vis,stack<int>&st)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[i])
        dfs(adj,i,vis,st);
    }
    st.push(node);
}
vector<int> topoSort(int n, vector<int> adj[]) 
{
    //using BFS
    int indegree[n]={0};
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        indegree[it]++;
    }
    vector<int>topo;
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(q.size()>0)
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        //node is in toposort. so remove it  from indegree
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    return topo;
}
int main() {
    vector<vector<int>>graph;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;cin>>x>>y;
        graph.push_back({x,y});
    }
    vector<int> adj[n];
    for(auto i:graph)
    adj[i[0]].push_back(i[1]);
    vector<int>vis(n,0);
    vector<int>topo=topoSort(n,adj);
    /*stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        dfs(adj,i,vis,st);
    }
    vector<int>topo;
    while(st.size()>0)
    {
        topo.push_back(st.top());
        st.pop();
    };*/
    for(auto i:topo)
    cout<<i<<" ";
 return 0;
}