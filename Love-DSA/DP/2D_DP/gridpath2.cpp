#include <bits/stdc++.h>
using namespace std;
/*
i/p: 0 0 0  o/p : 2
     0 1 0
     0 0 0
->we want to reach 0,0 to index n-1,m-1.but we can't move through path that have 1.
*/
long long M = 1e9 + 7;
int solve1(int n, int m, vector<vector<int>> &grid)
{
    if (n >= 0 && n >= 0 && grid[n][m] == 1)
        return 0;
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;

    return solve1(n - 1, m, grid) + solve1(n, m - 1, grid);
}
int solve2(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &v)
{
    if (n >= 0 && n >= 0 && grid[n][m] == 1)
        return 0;
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;
    if (v[n][m] != -1)
        return v[n][m] % M;
    v[n][m] = solve2(n - 1, m, grid, v) + solve2(n, m - 1, grid, v);
    return v[n][m] % M;
}
int solve3(int n, int m, vector<vector<int>> &grid)
{
    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            if (grid[i][j] == 1 && (i == 0 || j == 0))
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] != 1)
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % M;
            else
                dp[i][j] = 0;
        }
    }
    return dp[n - 1][m - 1];
}
// number of unique path from 0,0 to n-1,m-1 cell
int solve(int n, int m, vector<vector<int>> &dp)
{
    if (dp[n][m] != -1)
        return dp[n][m];
    if (n == 0 || m == 0)
        return 0;
    return dp[n][m] = 1 + solve(n - 1, m, dp) + solve(n, m - 1, dp);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    // int ans1=solve1(n-1,m-1,grid);
    // return ans1;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, -1));
    // int ans2=solve2(n-1,m-1,grid,v);
    // return ans2%M;
    int ans3 = solve3(n, m, grid);
    cout << ans3;
    return 0;
}