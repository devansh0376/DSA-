#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// 1 : LCS
int solve1(string s, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (s[n - 1] == y[m - 1])
        return 1 + solve1(x, y, n - 1, m - 1);
    else
        return max(solve1(x, y, n - 1, m), solve1(x, y, n, m - 1));
}
int solve2(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int longestCommonSubsequence(string s, string t)
{
    int n = s.size();
    int m = t.size();
    return solve2(s, t, n, m);
}
// 2 : print LCS
string solve2(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;
    string s = "";
    while (i > 0 && j > 0)//we start from last cell
    {
        if(x[i - 1] == y[j - 1]) 
        {
            s+=x[i - 1];
            i--;
            j--;
        }
        else
        {
            if(dp[i][j - 1] > dp[i - 1][j])
            j--;
            else
            i--;
        }
    }
    return s;
}
// 3 : minimum number of insertion and delation to make x->y
// # of insetion =n-LCS(X,y) and # of delation =m-LCS(X,y)
int solve2(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int minDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    return n + m - 2 * solve2(s, t, n, m);
}
// 4 : min number of delation/insertion to make string palimdrom
// n - LCS(x,y) y=reverse(x)
int minInsertions(string s)
{
    string x = s;
    reverse(s.begin(), s.end());
    string y = s;
    int n = s.size();
    return n - solve2(x, y, n, n);
}
// 5: SCS : sortect common super sequnce : meage x and y such that x and y both present in from of subseunce
// length of SCS : n+m - LCS(X,Y)
// print SCS
void ans1(string x, string y, int n, int m, string &ans)
{
    // code for LCS lenght table
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // code for print SCS with some change in code of SCS
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] < dp[i][j - 1]) // dp[i][j-1] if bigger here j-1 ,so we push y[j-1]
            {
                ans.push_back(y[j - 1]);
                j--;
            }
            else
            {
                ans.push_back(x[i - 1]);
                i--;
            }
        }
    }
    // If one string is "ab" and other one if " " so LCS=" " but SCS="ab"
    //  so following code for this condition
    while (i > 0) // if j=0 mean string y is empty
    {
        ans.push_back(x[i - 1]);
        i--;
    }
    while (j > 0) // if i=0 mean string x is empty
    {
        ans.push_back(y[j - 1]);
        j--;
    }
}
string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    string s = "";
    ans1(str1, str2, n, m, s);
    reverse(s.begin(), s.end());
    return s;
}
// 6 :disting subsequnce
/*
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit,rabbbit,rabbbit
*/
int solve1(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if (m == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (x[n - 1] == y[m - 1])
        return dp[n][m] = solve1(x, y, n - 1, m, dp) + solve1(x, y, n - 1, m - 1, dp);
    else
        return dp[n][m] = solve1(x, y, n - 1, m, dp);
}
int solve2(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}
int numDistinct(string s, string t)
{
    int n = s.size(), m = t.size();
    // return solve2(s,t,n,m);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve1(s, t, n, m, dp);
}

// 7: Edit distance
/*
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
*/
/*
    horse
    ros
    */
int solve1(string x, string y, int n, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (x[n - 1] == y[m - 1])
        return 0 + solve1(x, y, n - 1, m - 1);
    else
    {
        int insertion = 1 + solve1(x, y, n, m - 1);
        int deletion = 1 + solve1(x, y, n - 1, m);
        int replace = 1 + solve1(x, y, n - 1, m - 1);
        return min(insertion, min(deletion, replace));
    }
}
int solve2(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            if (j == 0)
                dp[i][j] = i;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 0;
            else
            {
                int insertion = 1 + dp[i][j - 1];
                int deletion = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(insertion, min(deletion, replace));
            }
        }
    }
    return dp[n][m];
}
int minDistance(string x, string y)
{
    int n = x.size(), m = y.size();
    int ans = solve2(x, y, n, m);
    return ans;
}
int main()
{
    return 0;
}