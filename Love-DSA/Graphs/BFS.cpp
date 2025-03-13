#include<bits/stdc++.h>
using namespace std;
//when we need to trverse and do not need to be connceted graph , this time we use bfs
int main() {
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
    int start=0;
    queue<int>q;
    int vis[n]={0};
    q.push(start);
    vis[start]=1;
    vector<int>bfs;
    while(q.size()>0)
    {
        int x=q.front();
        q.pop();
        bfs.push_back(x);
        for(auto it:adj[x])
        {
            if(vis[it]==0)
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
    for(auto i:bfs)
    cout<<i<<" ";

 return 0;
}