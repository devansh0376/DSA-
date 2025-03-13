#include<bits/stdc++.h>
using namespace std;
// max sum of non adjacent element or house robber(theif )
/*
i/p : 5 5 10 100 10 5 , o/p : 110
-> we have to take or not take element . if we take element so we can't take it's adjacent element so we do (n-2).if we don't take element we do (n-1)
*/
//recursion + memoization
int solve1(int arr[],int n,vector<int>&v)
{
    if(n==0)
    return arr[n];
    if(n<0)
    return 0;
    if(v[n]!=-1)
    return v[n];
    v[n]=max(arr[n]+ solve1(arr,n-2,v), 0+solve1(arr,n-1,v));
    return v[n];
}
//tabulation
int solve2(int arr[],int n)
{
    int dp[n+1];
    dp[0]=arr[0];
    int l=0,r=0;
    for(int i=1;i<=n;i++)
    {
        if(i>1)
        l=arr[i]+dp[i-2];
        r=0+dp[i-1];
        dp[i]=max(l,r);
    }
    return dp[n];
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int>v(n+1,-1);
    int ans1=solve1(arr,n-1,v);
    int ans2=solve2(arr,n-1);
    //cout<<ans1<<endl;
    cout<<ans2<<endl;
 return 0;
}