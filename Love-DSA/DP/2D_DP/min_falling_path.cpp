#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int solve1(int i, int j, vector<vector<int>> arr, int n, int m)
{
    if (j < 0 || j >= m)
        return 1e9;
    if (i == n - 1)
        return arr[i][j];
    int st = arr[i][j] + solve1(i + 1, j, arr, n, m);
    int ld = arr[i][j] + solve1(i + 1, j + 1, arr, n, m);
    int rd = arr[i][j] + solve1(i + 1, j - 1, arr, n, m);
    return min(st, min(ld, rd));
}
int solve3(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    for (int j = 0; j < m; j++)
        dp[n - 1][j] = arr[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            int st, lf, rt;
            st = lf = rt = INT_MAX;
            st = arr[i][j] + dp[i + 1][j];
            if (j > 0)
                lf = arr[i][j] + dp[i + 1][j - 1];
            if (j < m - 1)
                rt = arr[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(st, min(lf, rt));
        }
    }
    int result = INT_MAX;
    for (int j = 0; j < m; j++)
        result = min(result, dp[0][j]);

    return result;
}
int minFallingPathSum(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    /*int i=-1;
    int ans1=INT_MAX;
    for(int j=0;j<m;j++)
    ans1=min(ans1,solve1(i+1,j,arr,n,m));
    return ans1;*/
    int ans = solve3(arr);
    return ans;
}
int main()
{
    return 0;
}