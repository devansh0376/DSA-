#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/
int solve2(vector<int>& arr,int i,int buy,int n,vector<vector<int>> &dp)
{
    if(i==n)
    return 0;
    int op1,op2;
    if( dp[i][buy]!=-1)
    return  dp[i][buy];
    if(buy==0)//we can buy
    {
        op1=-arr[i]+solve2(arr,i+1,1,n,dp);//we buy the stocks
        op2=0+solve2(arr,i+1,0,n,dp);//we don't buy
    }
    else
    {
        op1=arr[i]+solve2(arr,i+1,0,n,dp);//we sell the stocks
        op2=0+solve2(arr,i+1,1,n,dp);//we donn't sell
    }
    return dp[i][buy]=max(op1,op2);
}
int solve1(vector<int>& arr,int i,int buy,int n)
{
    
    if(i==n)
    return 0;
    int op1,op2;
    if(buy==0)//we can buy else we can't buy
    {
        op1=solve1(arr,i+1,0,n);//we don't buy
        op2= -arr[i]+solve1(arr,i+1,1,n);//we buy stock
    }
    else//we can sell or not sell the stock
    {
        op1=solve1(arr,i+1,1,n);//we don't sell the stock
        op2=arr[i]+solve1(arr,i+1,0,n);//we sell the stock
    }
    return max(op1,op2);
}
int solve3(vector<int>& arr,int n)
{
    vector<vector<int>> dp(n+1,vector<int>(2,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<2;j++)
        {
            int op1=0,op2=0;
            if(j==0)
            {
                op1=-arr[i]+dp[i+1][1]; // we buy
                op2=dp[i+1][0];//we don't buy
            }
            else
            {
                op1=arr[i]+dp[i+1][0];//we sell
                op2=dp[i+1][1]; // we donn't sell 
            }
            dp[i][j]=max(op1,op2);
        }
    }
    return dp[0][0];
}
int main() {
    int n;cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        arr.push_back(x);
    }
    vector<vector<int>> dp(n,vector<int>(2,-1));
    int ans1=solve1(arr,0,0,n);
    int ans2=solve2(arr,0,0,n,dp);
    int ans3=solve3(arr,n);   
    cout<<ans1<<endl; 
    cout<<ans2<<endl; 
    cout<<ans3<<endl; 
 return 0;
}