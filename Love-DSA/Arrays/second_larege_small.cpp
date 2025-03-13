#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    int mx1 = INT_MIN, mx2 = INT_MIN;
    int mn1 = INT_MAX, mn2 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mn1 > arr[i])
        {
            mn2 = mn1;
            mn1 = arr[i];
        }
        else if (mn2 > arr[i] && arr[i] != mn1)
            mn2 = arr[i];

        if (mx1 < arr[i])
        {
            mx2 = mx1;
            mx1 = arr[i];
        }
        else if (mx2 < arr[i] && arr[i] != mx1)
            mx2 = arr[i];
    }
    cout<<mx2<<" "<<mn2<<endl;
    return 0;
}