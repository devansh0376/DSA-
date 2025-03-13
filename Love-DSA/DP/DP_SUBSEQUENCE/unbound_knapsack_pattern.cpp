#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// we can take item unlimited time
// 1:unbounded knapsack or rod cutting
int solve(int arr[], int price[], int length, int n)
{
    if (n == 0 || length == 0)
        return 0;
    if (arr[n - 1] <= length)
        return max(price[n - 1] + solve(arr, price, length - arr[n - 1], n), solve(arr, price, length, n - 1));
    else
        return solve(arr, price, length, n - 1);
}
int solve1(int price[], int length[], int n)
{
    int dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    // (n,n) ->(i,j)
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][n];
}
int cutRod(int price[], int n)
{
    // code
    int arr[n]; //we make out own length array 
    for (int i = 1; i <= n; i++)
        arr[i - 1] = i;

    // int ans=solve(arr,price,n,n);
    int ans = solve1(price, arr, n);
    return ans;
}
// coin change 1 : minimum number of coin to make sum=amount
int m = 1e4;
int solve1(vector<int> arr, int sum, int n)
{
    if(sum==0) return 0;
    if(n<=0) return 1e9;
    int t,nt;

    t=nt=1e9;

    if(coin[n-1]<=amount)
    t=1+solve(coin,amount-coin[n-1],n);
    nt=0+solve(coin,amount,n-1);

    return min(t,nt);
}
//n->i , sum->j
int solve(vector<int> arr, int n, int sum)
{
    int n=coin.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int j=1;j<sum+1;j++)
    dp[0][j]=1e9;

    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
            dp[i][j]=min(1+dp[i][j-coin[i-1]], 0 +dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][amount];
}
int coinChange(vector<int> &-, int sum)
{
    int n = arr.size();
    return solve1(arr, sum, n);
}
// coin change 2 : total number of ways to make a amount
int solve1(vector<int> &coin,int amount,int n,vector<vector<int>> &dp)
{
    if(n<=0)
    return 0;
    if(amount==0)
    return 1;
    if(dp[n][amount]!= -1)
    return dp[n][amount];
    if(coin[n-1]<=amount)
    return dp[n][amount]= solve1(coin,amount-coin[n-1],n,dp)+solve1(coin,amount,n-1,dp);
    else
    return dp[n][amount]=solve1(coin,amount,n-1,dp);
}
int solve(vector<int> arr, int n, int x)
{
    int dp[n + 1][x + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < x + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    //(n,x)->(i,j)
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][x];
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    return solve(coins, n, amount);
}
int main()
{
    return 0;
}