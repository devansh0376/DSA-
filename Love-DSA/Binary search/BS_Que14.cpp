#include <bits/stdc++.h>
using namespace std;
// Minimum Number of Days to Make m Bouquets
/*
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
k=flower and m=box. we have to fill tree box with conditon that each box must have k flowers. and we can fill this adjcent fower.and array containes days in which flower will bloom.
*/
int solve(vector<int> arr, int m, int k)
{
    int n = arr.size();
    if ((long long)(m) * (long long)k > n)
        return -1;
    // int l=*min_element(arr.begin(),arr.end());
    int l = 1;
    int h = *max_element(arr.begin(), arr.end());
    int ans = INT_MAX;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int ct = 0, bk = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= mid)
            {
                ct++;
                if (ct == k)
                { 
                    ct = 0;
                    bk++;
                }
            }
            else
                ct = 0;
        }
        if (bk >= m)
        {
            ans = min(ans, mid);
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
int main()
{
    int size,n,m;cin>>size>>n>>m;
    vector<int>arr;
    for(int i=0;i<size;i++)
    {
        int x;cin>>x;
        arr.push_back(x);
    }
    cout<<solve(arr,n,m);
    return 0;
}