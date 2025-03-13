#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// main template
int main(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    if (wt[n - 1] <= w)
        return max(val[n - 1] + solve1(wt, val, w - wt[n - 1], n - 1), solve1(wt, val, w, n - 1));
    else
        return solve1(wt, val, w, n - 1);
}
// 1 : check whether there exist subset sum=k
bool solve1(vector<int> arr, int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (arr[n - 1] <= sum)
        return (solve1(arr, n - 1, sum - arr[n - 1]) || solve1(arr, n - 1, sum));
    else
        return solve1(arr, n - 1, sum);
}
bool solve2(vector<int> arr, int n, int sum, vector<vector<int>> v)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (v[n][sum] != -1)
        return v[n][sum];
    if (arr[n - 1] <= sum)
        return v[n][sum] = (solve1(arr, n - 1, sum - arr[n - 1]) || solve1(arr, n - 1, sum));
    else
        return v[n][sum] = solve1(arr, n - 1, sum);
}
//n -->i , sum -->j
bool solve3(vector<int> arr, int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    // bool ans1=solve1(arr,n,sum);
    // return ans1;
    vector<vector<int>> v(n + 1, vector<int>(sum + 1, -1));
    // bool ans2=solve2(arr,n,sum,v);
    // return ans2;
    bool ans3 = solve3(arr, n, sum);
    return ans3;
}

// 2 : check there is possible to divide array into two part such that sum1=sum2
bool solve1(vector<int> arr, int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (arr[n - 1] <= sum)
        return (solve1(arr, n - 1, sum - arr[n - 1]) || solve1(arr, n - 1, sum));
    else
        return solve1(arr, n - 1, sum);
}
bool solve2(vector<int> arr, int n, int sum, vector<vector<int>> v)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (v[n][sum] != -1)
        return v[n][sum];
    if (arr[n - 1] <= sum)
        return v[n][sum] = (solve1(arr, n - 1, sum - arr[n - 1]) || solve1(arr, n - 1, sum));
    else
        return v[n][sum] = solve1(arr, n - 1, sum);
}
bool solve3(vector<int> arr, int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
bool canPartition(vector<int> &arr)
{
    int n = arr.size();
    int k = accumulate(arr.begin(), arr.end(), 0);
    if (k % 2 != 0)
        return 0;
    int sum = (k / 2);
    // bool ans1=solve1(arr,n,sum);
    // return ans1;
    vector<vector<int>> v(n + 1, vector<int>(sum + 1, -1));
    bool ans2 = solve2(arr, n, sum, v);
    return ans2;
    // bool ans3=solve3(arr,n,sum);
    // return ans3;
}
// 4:count of subset whose sum=k
int solve(int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    if (sum <= arr[n - 1])
        return solve(arr, n - 1, sum - arr[n - 1]) + solve(arr, n - 1, sum);
    else
        return solve(arr, n - 1, sum);
}
long long mod = 1e9 + 7;
int solve3(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = (j == 0) ? 1 : 0; // 1 way to get sum 0 with 0 elements, 0 ways for other sums
            }
            else if (j == 0)
            {
                dp[i][j] = 1; // 1 way to get sum 0 (by choosing no elements)
            }
            else
            {
                dp[i][j] = 0; // Initialize the rest to 0
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % mod;
        }
    }
    return dp[n][sum];
}
int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    return solve(arr, n, sum);
}
// 5:minimum subset sum differece.divide array in two part such that abs(s1-s2) is minimum
int solve(int arr[], int n, int sum, int range)
{
    if (n == 0)
        return abs(range - sum - sum);

    return min(solve(arr, n - 1, sum - arr[n - 1], range), solve(arr, n - 1, sum, range));
}
int solve1(int arr[], int n, int sum, int range, vector<vector<int>> &dp)
{
    if (n == 0)
        return abs(range - sum - sum);

    if (dp[n][sum] != -1)
        return dp[n][sum];

    return dp[n][sum] = min(solve1(arr, n - 1, sum - arr[n - 1], range, dp), solve1(arr, n - 1, sum, range, dp));
}
int solve2(int arr[], int n, int sum, int range)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    vector<int> v;
    for (int j = 0; j <= sum / 2; j++)
    {
        if (dp[n][j] == true)
            v.push_back(j);
    }
    int mini = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        mini = min(mini, sum - 2 * v[i]);
    }
    return mini;
}
int minDifference(int arr[], int n)
{
    // Your code goes here
    int sum = accumulate(arr, arr + n, 0);
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    // return solve(arr,n,sum,sum);
    // return solve1(arr,n,sum,sum,dp);
    return solve2(arr, n, sum, sum);
}

// 6:count of subset with given difference
/*
->here we want to find number of subset whose diferece is K
we know s1+s2=sum
        s1-s2=diff
        s1=(diff+sum)/2
        for not overflow use s2=(sum-diff)/2
->find the count of subset whose sum is equal to (diff+sum)/2
 */

int mod = 1e9 + 7;
int solve1(vector<int> arr, int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (arr[n - 1] <= sum)
        return solve1(arr, n - 1, sum - arr[n - 1]) + solve1(arr, n - 1, sum);
    else
        return solve1(arr, n - 1, sum);
}
int ans1(vector<int> arr, int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
            }
            else
                dp[i][j] = dp[i - 1][j] % mod;
        }
    }
    return dp[n][sum] % mod;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    // Code here
    int old_sum = 0;
    for (int i = 0; i < n; i++)
        old_sum += arr[i] % mod;
    if (d > old_sum || (old_sum - d) % 2)
        return 0;
    int ans = ans1(arr, n, (old_sum - d) / 2);
    return ans % mod;
}

// 7:target sum : we want to assing + or - sign to array so that our array sum=target
int solve(vector<int> arr, int sum)
{
    int n = arr.size();
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int findTargetSumWays(vector<int> &nums, int target)
{
    /*
    ->here we want to assing + or - sign to array so that our array sum=target
EX:1    1 1 1 1 1
        - + + + +
    -1  1 1 1 1 it is like find two subset whose difference is equal to target.

EX:2    1 1 1 1 1
        + - + + +
    1  -1 1 1 1 => -1 1 1 1 1 =another subset
    ->it is same question : count subsets with difference equal to k here k=taeget
    */
    int sum = accumulate(nums.begin(), nums.end(), 0);
    /*
    s1+s2=sum
    s1-s2=diff => s1= (sum+diff)/2
    here we do s2=(sum-diff)/2 for not overflow
    */
    if (target > sum || (sum - target) % 2)
        return 0;
    int new_target = (sum - target) / 2;
    int ans = solve(nums, new_target);
    return ans;
}

int main()
{
    return 0;
}