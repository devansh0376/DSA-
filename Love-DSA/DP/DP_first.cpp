#include <bits/stdc++.h>
using namespace std;
/*
->DP is use for optimize the recursion.
->In DP we store the ans thar we calucated and so in future we don't need to caculate the ans.
->there are two kind of DP. top down(memoization) : recursion+memoization and bottom up(tabulation)
*/
// recusive solution
int ans1(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return ans1(n - 1) + ans1(n - 2);
}
// top down approch
int ans2(int n, vector<int> v)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (v[n] != -1)
        return v[n];
    v[n] = ans2(n - 1, v) + ans2(n - 2, v);
    return v[n];
}
// bottom up
int ans3(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// min cost to reach n-1th stairs
// memoization
int solve1(vector<int> arr, int n, vector<int> &v)
{
    if (n == 0)
        return 0;
    if (v[n] != -1)
        return v[n];
    int l = solve1(arr, n - 1, v) + abs(arr[n] - arr[n - 1]);
    int r = INT_MAX;
    if (n > 1)
        r = solve1(arr, n - 2, v) + abs(arr[n] - arr[n - 2]);
    v[n] = min(l, r);
    return v[n];
}
// tabulation
int solve2(vector<int> arr, int n)
{
    int dp[n + 1];
    dp[0] = 0;
    int l, r = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        l = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        if (i > 1)
            r = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        dp[i] = min(l, r);
    }
    return dp[n];
}
// frog can jump k jumps
// tabulation
int solve(vector<int> arr, int n, int k)
{
    int dp[n + 1];
    dp[0] = 0;
    int min_step, jump;
    for (int i = 1; i <= n; i++)
    {
        min_step = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                min_step = min(min_step, jump);
            }
            dp[i] = min_step;
        }
    }
    return dp[n - 1];
}
// recursion
int solve2(vector<int> arr, int n, int k)
{
    if (n == 0)
        return 0;
    int mn = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int jump = solve2(arr, n - i, k) + abs(arr[n] - arr[n - i]);
            mn = min(mn, jump);
        }
    }
    return mn;
}
// minimum sum of non-adajencent element
int solve2(vector<int> arr, int n)
{
    if (n == 0)
        return arr[0];
    if (n < 0)
        return 0;
    int nt = solve2(arr, n - 1) + 0;
    int t = solve2(arr, n - 2) + arr[n];
    return max(t, nt);
}
int main()
{
    int n;
    cin >> n;
    cout << ans1(n) << endl;
    vector<int> v(n + 1, -1);
    cout << ans2(n, v) << endl;
    cout << ans3(n) << endl;
    return 0;
}
