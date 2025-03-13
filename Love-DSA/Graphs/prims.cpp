#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
->spaning Tree : A spanning tree is a tree in which we have N nodes(i.e. All the nodes present in the original graph) and N-1 edges and all nodes are reachable from each other.
->Minimum spaning Tree : minimum spanning tree is the one for which the sum of all the edge weights is the minimum.
*/
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> > pq; //{wt,node}
    int sum=0;
    pq.push({0,0});
    vector<int> vis(V,0);
    while(pq.size()>0)
    {
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();
        if(vis[node])
        continue;
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node])
        {
            int adjnode=it[0],edjwt=it[1];
            if(vis[adjnode]==0)
            pq.push({edjwt,adjnode});
        }
    }
    return sum;
}
int main() {
 return 0;
}