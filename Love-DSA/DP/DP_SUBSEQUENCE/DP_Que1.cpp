#include<bits/stdc++.h>
using namespace std;
// 0-1 knapsack
/*
->in 0-1 knapsack one item one supply. if we have 4 kg and spacce of bag is 3kg so we can't take it. in fraction knapsack we can take it
i/p: val[]:1 4 5 7 o/p: 9
      wt[]:1 3 4 5
      W=7   
base case : thik of smallest valid input or invalid input
*/
int solve1(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
    return 0;
    if(wt[n-1]<=w)
    return max(val[n-1]+solve1(wt,val,w-wt[n-1],n-1),solve1(wt,val,w,n-1));
    else
    return solve1(wt,val,w,n-1);
}
int solve2(int wt[],int val[],int w,int n,vector<vector<int>> &v)
{
    if(n==0||w==0)
    return 0;
    if(v[n][w]!=-1)
    return v[n][w];
    if(wt[n-1]<=w)
    return v[n][n]=max(val[n-1]+solve1(wt,val,w-wt[n-1],n-1),solve1(wt,val,w,n-1));
    else
    return v[n][w]=solve1(wt,val,w,n-1);
}
// n=i ans w=j 
int solve3(int wt[],int val[],int w,int n)
{
    int dp[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
int main() {
    int n;cin>>n;
    int wt[n],val[n];
    for(auto &i:val)cin>>i;
    for(auto &i:wt)cin>>i;
    int w;cin>>w;
    int ans1=solve1(wt,val,w,n);
    cout<<ans1<<endl;
    vector<vector<int>>v(n+1,vector<int>(w+1,-1));
    int ans2=solve2(wt,val,w,n,v);
    cout<<ans2<<endl;
    int ans3=solve3(wt,val,w,n);
    cout<<ans3<<endl;
 return 0;
}