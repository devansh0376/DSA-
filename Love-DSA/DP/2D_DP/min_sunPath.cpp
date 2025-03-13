#include <bits/stdc++.h>
using namespace std;
// minimum sum path in matrix
/*
i/p :1 3 5 o/p:7 )- 1->2->1->2->1
     2 1 2
     4 3 1
-> we have try all path and select minimum
->
*/
int solve1(int n, int m, vector<vector<int>> &grid)
{
    if (n == 0 && m == 0)
        return grid[n][m];
    if (n < 0 || m < 0)
        return 1e9;
    return grid[n][m] + min(solve1(n, m - 1, grid), solve1(n - 1, m, grid));
}
int solve2(int n, int m, vector<vector<int>> grid, vector<vector<int>> &v)
{
    if (n == 0 && m == 0)
        return grid[n][m];
    if (n < 0 || m < 0)
        return 1e9;
    if (v[n][m] != -1)
        return v[n][m];

    v[n][m] = grid[n][m] + min(solve2(n, m - 1, grid, v), solve2(n - 1, m, grid, v));
    return v[n][m];
}
int solve3(int n, int m, vector<vector<int>> grid)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j != 0)
                grid[i][j] += grid[i][j - 1];
            if (i != 0 && j == 0)
                grid[i][j] += grid[i - 1][j];
            if (i != 0 && j != 0)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[n - 1][m - 1];
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
    vector<vector<int>> v(n, vector<int>(m, -1));
    // int ans2=solve2(n-1,m-1,grid,v);
    // return ans2;
    int ans3 = solve3(n, m, grid);
    cout << ans3;
    return 0;
}