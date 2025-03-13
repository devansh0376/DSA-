#include<bits/stdc++.h>
using namespace std;
/*
N = 3, W = 50,values[] = {60,100,120},weight[] = {10,20,30}
Output:240.00
Explanation:Total maximum value of item we can have is 240.00 from the given capacity of sack. 
*/
/*
->in this question we have to take items such that we can maximize out profit.
->greedy approch : we take item which have higest weight by value.
we want value max: (val/weight )increser -> val increase
val[]=   60 100 120
wt[] =   10 20 30
wt/val[]=6  5  4
->now we sort in deseding order.then add to our knapsack.
*/
int main() {
    int n;cin>>n;
    int w;cin>>w;
    int val[n],wt[n];
    for(auto &i:val)cin>>i;
    for(auto &i:wt)cin>>i;
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
    cout<<ans<<endl;
 return 0;
}