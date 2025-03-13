#include<bits/stdc++.h>
using namespace std;
//helps to find shortest path from source node 
//single source sortest path alorithm
//we use max heap
int main() {
    int n,e;cin>>n>>e;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<e;i++)
    {
        int node1,node2,weight;cin>>node1>>node2>>weight;
        adj[node1].push_back({node2,weight});
        adj[node2].push_back({node1,weight});
    }
    //node,weight
   /* priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>dist(n,1e9);
    dist[0]=0;
    pq.push({0,0}); // dist,node
    while(pq.size()>0)
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it : adj[node])
        {
            int adjnode=it.first;
            int edgewt=it.second;
            if(dis+edgewt < dist[adjnode])
            {
                dist[adjnode]=dis+edgewt;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }*/
    //using set 
    set<pair<int,int>>st; //dist,node
    vector<int>dist(n,1e9);
    st.insert({0,0});
    while(st.size()>0)
    {
        auto it=*st.begin();
        int node=it.second;
        int dis=it.first;
        st.erase(it);
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int edgewt=it.second;
            if(dis +edgewt < dist[adjnode])
            {
                if(dist[adjnode]!=1e9) 
                st.erase({dist[adjnode],adjnode});
                dist[adjnode]=dis+edgewt;
                st.insert({dist[adjnode],adjnode});
            }
        }
    }
    for(auto i:dist)
    cout<<i<<" ";

 return 0;
}
//for 2D matrix 
//1091. Shortest Path in Binary Matrix
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        return -1;
        /*
        queue<pair<int,int>>q; // (i,j)
        q.push({0,0});
        int dx[8]={1,-1,0,0,1,1,-1,-1};
        int dy[8]={0,0,1,-1,1,-1,1,-1};      
        int step=0;
        while(q.size()>0)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r==n-1 && c==n-1)
                return step+1;
                for(int j=0;j<8;j++)
                {
                    int dr=r+dx[j];
                    int dc=c+dy[j];
                    if(dr>=0 && dr<n && dc>=0 && dc<m && grid[dr][dc]==0)
                    {
                        grid[dr][dc]=1;
                        q.push({dr,dc});
                    }
                }
            }
            step++;
        }
        return -1;*/
        //using dijkstra algo
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        vector<vector<int>>result (n,vector<int>(n,INT_MAX)) ;
        result[0][0]=0;
        int dx[8]={1,-1,0,0,1,1,-1,-1};
        int dy[8]={0,0,1,-1,1,-1,1,-1}; 
        while(pq.size()>0)
        {
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int dist=pq.top().first;
            if(r==n-1 && c==n-1)
            return dist+1;
            pq.pop();
            for(int i=0;i<8;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]==1)
                continue;
                if(dist + 1 <result[nr][nc])
                {
                    result[nr][nc]=dist + 1 ;
                    grid[nr][nc]=1;
                    pq.push({dist + 1 ,{nr,nc}});
                }
            }
        }
        // if(result[n-1][n-1]==INT_MAX)
        // return -1;
        // else
        // return result[n-1][n-1]+1;
        return -1;
    }
};