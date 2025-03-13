#include <bits/stdc++.h>
using namespace std;
//when we need to traverse but we need conneted graph,so this time we use DFS
void dfs(vector<int> adj[],int node,vector<int> &vis,vector<int> &ans)
{
    vis[node]=1;
    ans.push_back(node);
    for(auto i:adj[node])
    {
        if(vis[i]==0)
        dfs(adj,i,vis,ans);
    }   
}
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    // Code here
    vector<int>vis(n,0); 
    int start=0;
    vector<int>ans;
    dfs(adj,start,vis,ans);
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans=dfsOfGraph(n,adj);
    for(auto i:ans)
    cout<<i<<" ";
    return 0;
}