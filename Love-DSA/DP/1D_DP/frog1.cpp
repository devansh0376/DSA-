#include<bits/stdc++.h>
using namespace std;
/*
i/p:10 20 30 10 
o/p:20
->we can take jump either one or two jump.and the energy to take jump to jth stone to ith stone if abs(a[i]-a[j])
->we want to find minimum energy to reach nth stair
->one possible solution if greedy method. if we at ith stone we go min(a[i]-a[i+1],a[i]-a[i+2]).but this not true for all cases. ex : 30 10 60 10 60 50
*/
#include <bits/stdc++.h> 
/*
int solve(vector<int>arr,int n)
{
    if(n==0)
    return 0;
    int l=solve(arr,n-1)+abs(arr[n]-arr[n-1]);
    int r=INT_MAX;
    if(n>1)
    r=solve(arr,n-2)+abs(arr[n]-arr[n-2]);

    return min(l,r);
}

int solve1(vector<int>arr,int n,vector<int>&v)
{
    if(n==0)
    return 0;
    if(v[n]!=-1)
    return v[n];
    int l=solve1(arr,n-1,v)+abs(arr[n]-arr[n-1]);
    int r=INT_MAX;
    if(n>1)
    r=solve1(arr,n-2,v)+abs(arr[n]-arr[n-2]);
    v[n]=min(l,r);
    return v[n];
}
*/
int solve2(vector<int>arr,int n)
{
    int dp[n+1];
    dp[0]=0;
    int l,r=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        l=dp[i-1]+abs(arr[i]-arr[i-1]);
        if(i>1)
        r=dp[i-2]+abs(arr[i]-arr[i-2]);
        dp[i]=min(l,r);
    }
    return dp[n];
}
int main() {
    int n;cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        arr.push_back(x);
    }
    //int ans=solve(arr,n-1);
    vector<int>v(n+1,-1);
    //int ans=solve1(arr,n-1,v);
    int ans=solve2(arr,n-1);
    cout<< ans; 
 return 0;
}