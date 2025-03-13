#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
->when is toposort aplicaple ? when it is a directed and acycle graph.
->in topo sort all node is edge wise sort ex: u->v->z so toposort : u,v,z
->if graph is cyclic so topo sort is not aplicaple so we can use the this for detecting cycle in directed graph
->whenever cycle in directed graph , x come before y, given question so there is a toposort aplicable
*/
/*
=>using dfs 
simple dsf when we back from recursion push node into stack 
=>using bfs(kahan's algo)
here we use indegree concept three steps: 1>make indegree vector 2>push all node in queue with indegree zero 3>simple bfs every time we do inderee[node]-- if it is zero then we push into queue. wheneever we pop from queue so it a node with indegree zero so it will be part of our ans so push into ans 
*/

//207. Course Schedule : take course a before course b , return if we can do all course.
//simple if it a cycle like you have to a before b and b before a so you can't do all couese
/*
bool detect_cycle_dfs(vector<int> adj[],int node,vector<int> &vis,vector<int> &inrecursion)
{
    vis[node]=true;
    inrecursion[node]=true;
    
    for(auto i:adj[node])
    {
        if(vis[i]!=true)
        {
            if(detect_cycle_dfs(adj,i,vis,inrecursion))
            return true;
        }
        else if(inrecursion[i])
        return true;
    }
    inrecursion[node]=false;
    return false;
}
bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //here we have to just detect the cycle in graph if yes then we can't do all course
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        /*vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            indegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int cnt=0;
        while(q.size()>0)
        {
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(cnt==n)//topo sort can be aplly
        return true;
        else
        return false;
        //using dfs
        vector<int> vis(n,0),inrecursion(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=true)
            {
                if(detect_cycle_dfs(adj,i,vis,inrecursion))
                return false;
            }
        }
        return true;
    }
*/
//210. Course Schedule II : here you need to return of right ordered of cource take just return toposort vector

//802. Find Eventual Safe States : here you need to return all safe node
/*safenode : node with all path end at teminal node(has no outgoing edge) . here we reverse edge bcoz we can't do traversal. in topo sort if it a cycle so :
in dfs pathvis vector has all true value of node which are part of cycle 
in bfs indegree vector has indegree>0 value of node which are part cycle 
-here we need to return all end node which are not part of cycle 
*/
/*
bool detect(vector<int>adj[],int node,vector<int> &vis,vector<int>&pathvis)
{
    vis[node]=1;
    pathvis[node]=1;
    //tarverse adjacent node
    for(auto it:adj[node])
    {
        //if node is not previously visited
        if(vis[it]==0)
        {
            if(detect(adj,it,vis,pathvis)==true)
            {
                //check[node]=0;
                return true;
            }
        }
        // if node is visited and but it is on same path
        else if(pathvis[it])
        {
            //check[node]=0;
            return true;
        }
    }
    pathvis[node]=0;
    return false;
}
vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
    // code here
    vector<int> vis(v,0);
    vector<int> pathvis(v,0);
    vector<int>ans;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        detect(adj,i,vis,pathvis);
    }
    for(int i=0;i<v;i++)
    {
        if(pathvis[i]==0)
        ans.push_back(i);
    }
    return ans;

    //using BFS(kahan's algo / Topo sort algo )
    vector<int> adjrev[v];
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            adjrev[it].push_back(i);
            //step : 1
            indegree[i]++;
        }
    }
    //step 2 :push all node with indegree with zero
    vector<int> safenode;
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    //step 3:simple bfs
    while(q.size()>0)
    {
        int x=q.front();
        q.pop();
        safenode.push_back(x);
        for(auto i:adjrev[x])
        {
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    sort(safenode.begin(),safenode.end());
    return safenode;
}
*/
//Alien Dictionary : return the alien ordered from the stings given 
//for orderd charf(a)<char(b) means a come shoud before b. so we make a graph(mean ajd list) then return toposort vector
/*
void dfs(vector<int> adj[],int node,vector<int> &vis,stack<int> &s)
    {
        vis[node]=true;
        for(auto i:adj[node])
        {
            if(vis[i]!=1)
            dfs(adj,i,vis,s);
        }
        s.push(node);
    }
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int> adj[k];
        for(int i=0;i<n-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> topo;
        stack<int> s;
        vector<int> vis(k,0);
        
        for(int i=0;i<k;i++)
        {
            if(vis[i]!=1)
            dfs(adj,i,vis,s);
        }
        string ans="";
        while(s.size()>0)
        {
            ans+=s.top()+'a';
            s.pop();
        }
        return ans;
    }
*/
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
    
}