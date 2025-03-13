#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// when there are diiferent pattern to calculate ans and every pattern gives different ans so we can apply this
// all partition algo : here we have to find optimal ans amoung all partion there are number of partion is not given
// 1:MCM
int solve(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(arr, i, k, dp) + solve(arr, k + 1, j, dp);
        mn = min(mn, steps);
    }
    return dp[i][j] = mn;
}
int solve1(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mn = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int step = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mn = min(mn, step);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][n - 1];
}
int matrixMultiplication(int n, int arr[])
{
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    // return solve(arr,1,n-1,dp);
    return solve1(arr, n);
}
// 2:minimum cuts to sticks : we have to cut stick in minimum cost
int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int cost = arr[j + 1] - arr[i - 1] + solve(arr, i, k, dp) + solve(arr, k + 1, j, dp);
        mn = min(mn, cost);
    }
    return dp[i][j] = mn;
}
int solve1(vector<int> arr)
{
    int len = arr.size();
    vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));
    for (int i = len; i >= 1; i--)
    {
        for (int j = i; j <= len - 2; j++)
        {
            if (i > j)
                continue;
            int mn = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                int cost = arr[j + 1] - arr[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                mn = min(mn, cost);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][len - 2];
}
int minCost(int n, vector<int> &arr)
{
    int len = arr.size();
    arr.push_back(n);
    arr.insert(arr.begin(), 0);
    sort(arr.begin(), arr.end());
    vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
    // return solve(arr,1,len,dp);
    return solve1(arr);
}
// 3:burst balloons : If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
int solve(vector<int> arr, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mx = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        // int cost=arr[i-1]*arr[k]*arr[j+1];
        int rem_cost = arr[i - 1] * arr[k] * arr[j + 1] + solve(arr, i, k - 1, dp) + solve(arr, k + 1, j, dp);
        mx = max(mx, rem_cost);
    }
    return dp[i][j] = mx;
}
int solve1(vector<int> arr)
{
    int n = arr.size() - 2;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;
            int mx = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int cost = arr[i - 1] * arr[k] * arr[j + 1];
                int rem_cost = dp[i][k - 1] + dp[k + 1][j];
                mx = max(mx, cost + rem_cost);
            }
            dp[i][j] = mx;
        }
    }
    return dp[1][n];
}
int maxCoins(vector<int> &arr)
{
    int n = arr.size();
    arr.push_back(1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    arr.insert(arr.begin(), 1);
    return solve(arr, 1, n, dp);
    // return solve1(arr);
}

// left side partition algo : here number of partion is given as condition or we have to calculate min or max number of partion
// 1:palidrome partitioning
bool is_palimdrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
int solve(int idx, string s, vector<int> &dp)
{
    int cost = 0, mn = INT_MAX;
    if (idx == s.size())
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    for (int i = idx; i < s.size(); i++)
    {
        if (is_palimdrome(s, idx, i))
            cost = 1 + solve(i + 1, s, dp);
        mn = min(mn, cost);
    }
    return dp[idx] = mn;
}
int solve1(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int mn = INT_MAX;
        int cost = 0;
        for (int j = i; j < n; j++)
        {
            if (is_palimdrome(s, i, j))
                cost = 1 + dp[j + 1];  
            mn = min(mn, cost);
        }
        dp[i] = mn;
    }
    return dp[0] - 1;
}
int minCut(string s)
{
    vector<int> dp(s.size() + 1, -1);
    // return solve(s,0,dp)-1;
    // return solve1(s);
    return solve(0, s, dp) - 1;
}
// 2:partition array max sum : Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
int solve(vector<int> arr, int n, int i, int k, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int len = 0, mx = INT_MIN, ans = INT_MIN;
    for (int j = i; j < min(i + k, n); j++)
    {
        len++;
        mx = max(mx, arr[j]);
        int sum = mx * len + solve(arr, n, j + 1, k, dp);
        ans = max(ans, sum);
    }
    return dp[i] = ans;
}
int solve1(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0, mx = INT_MIN, ans = INT_MIN;
        for (int j = i; j < min(i + k, n); j++)
        {
            len++;
            mx = max(mx, arr[j]);
            int sum = mx * len + dp[j + 1];
            ans = max(ans, sum);
        }
        dp[i] = ans;
    }
    return dp[0];
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    // return solve(arr,n,0,k,dp);
    return solve1(arr, k);
}
int main()
{
    return 0;
}