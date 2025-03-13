#include<bits/stdc++.h>
using namespace std;
// fraction knapsack 
/*
->we have to maximize the profit.we are thief here so we take item first whose price er unit is higher
-> so we have to sort the two array WR to val/wt.
*/
int main() {
    int n,m;cin>>n>>m;
    int wt[n],val[m];
    for(auto &i:val)cin>>i;
    for(auto &i:wt)cin>>i;
    int w;cin>>w;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    v.push_back({val[i],wt[i]});
    auto cmp=[](pair<int,int>p1,pair<int,int>p2)
    {
        double v1=(double)p1.first/p1.second;
        double v2=(double)p2.first/p2.second;
        return v1>v2;
    };
    sort(v.begin(),v.end(),cmp);
    double ans=0;
    for(int i=0;i<n;i++)
    {
        if(w>=v[i].second)
        {
            ans+=v[i].first;
            w-=v[i].second;
            continue;
        }
        double vw=(double)v[i].first/v[i].second;
        ans+=(vw*w);
        break;
    }
    cout<<ans;    
 return 0;
}