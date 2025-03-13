#include <bits/stdc++.h> 
/*
	1. Consider taking input, output using fast Input-Output
	2. Include the essential imports only
*/

#include <iostream>

using namespace std;
bool detect_dfs(vector<int> adj[],int vis[],int node,int parent)
{
	vis[node]=1;
	for(auto i:adj[node])
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			detect_dfs(adj,vis,i,node);
		}
		//if node is alredy visited so it must be a parent of athore node but if this not.so there is cycle
		else if(vis[i] && parent!=i)
		return true;
	}
	return false;
}
/*
Explanation.
->Parent is nothing but the node from which we visited the current node.When a node is visited and it is not the parent, then we can say that there is a cycle.
->So, when we are calling DFS function for an unvisited node, then it checks its all nodes connected. If it finds any node already visited and not the parent, then there is cycle. If its a parent, then the cycle is still not detected. In the DFS function, we send an extra parameter known as parent, which is the node that is calling dfs of its child.
*/
bool detect_bfs(int src,vector<int> adj[],int vis[])
{
	vis[src]=1;
	queue<pair<int,int>>q;
	q.push({src,-1});
	while(q.size()>0)
	{
		int node=q.front().first;
		int parent=q.front().second;
		q.pop();
		for(auto i:adj[node])
		{
			//here node is parent and every i is a child of it
			if(vis[i]==0)
			{
				vis[i]=1;
				q.push({i,node});
			}
			else if(parent !=i)//means 7's parent is 5 but fronm other side we got that 7's parent is 6 so thre is cycle
			return true;
		}
	}
	return false;
}
int main() {

	/*
		1. You have to take the input by yourself as mentioned in the input format.
		2. You have to print the output by yourself as per the output format mentioned.
		3. You may start writing your code below this multi-line comments section.
	*/
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
	int vis[n]={0};
    vis[0]=1;
    int parent=-1;
	int ans=1;
    for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			if(!detect_bfs(i,adj,vis))
			//if(!detect_dfs(adj,vis,i,parent))
			{
				ans=0;
				break;
			}
		}
	}
	if(ans)cout<<"True";
	else cout<<"False";
	return 0;
}

