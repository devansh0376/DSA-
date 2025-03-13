#include <bits/stdc++.h>
using namespace std;
// number of uniqe apath to reach 0,0 to n-1,m-1 index
/*
i/p:2 o/p:2
->Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.
*/
int solve1(int n, int m)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;
    return solve1(n, m - 1) + solve1(n - 1, m);
}
int solve2(int n, int m, vector<vector<int>> &v)
{
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;
    if (v[n][m] != -1)
        return v[n][m];
    v[n][m] = solve2(n, m - 1, v) + solve2(n - 1, m, v);
    return v[n][m];
}
int solve3(int n, int m)
{
    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> v(a + 1, vector<int>(b + 1, -1));
    // int ans1=solve1(a-1,b-1);
    // return ans1;
    // int ans2=solve2(a-1,b-1,v);
    // return ans2;
    int ans3 = solve3(a, b);
     cout<<ans3<<endl;;
    return 0;
}