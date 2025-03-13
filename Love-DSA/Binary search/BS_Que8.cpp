#include <bits/stdc++.h>
using namespace std;
// Find Nth root of M
/*
Ex : 3 27 :-> 3^3=27 ans=3, 3 8:-> 2^3=8 ans=2
*/
int ans1(int n, int m)
{
    int a = 1;
    for (int i = 1; i <= m; i++)
    {
        a = 1;
        for (int j = 1; j <= n; j++)
        {
            a = a * i;
        }
        if (a == m)
            return i;
        if (a > m)
            return -1;
    }
}
int ans2(int n, int m)
{
    double l = 1, h = m;
    // double e=1e-7;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        double a = 1;
        for (int i = 1; i <= n; i++)
        {
            a = a * mid;
        }
        if (a == m)
            return mid;
        else if (a < m)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << ans1(n, m) << endl;
    cout << ans2(n, m) << endl;
    return 0;
}