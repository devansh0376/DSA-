//graphs representation in c++
//by adjacancy matrix
/*using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

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
    for(auto i:adj)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    for(auto i:adj)
    {
        for(auto j: i.second)
        cout<<j<<" ";

        cout<<endl;
    }
 return 0;

}*/