#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<pair<int,int>> adj[n+1];
        for(auto i:times)
        adj[i[0]].push_back({i[1],i[2]});

        //we use priority queue for dijkstra algo
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        vector<int> result(n+1,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        while(pq.size()>0)
        {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(auto i:adj[node])
            {
                int adjnode=i.first;
                int edjwt=i.second;
                if(edjwt+dist < result[adjnode])
                {
                    result[adjnode]=edjwt+dist;
                    pq.push({edjwt+dist,adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            ans=max(ans,result[i]);
        }

        if(ans==INT_MAX)
        return -1;
        else
        return ans;
    }
};

int main() {
    
 return 0;
}