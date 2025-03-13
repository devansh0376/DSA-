#include <bits/stdc++.h>
using namespace std;
// return majority element(repeat more than n/2 times)
int ans(int arr[], int n)
{

    // your code here
    /*map<int,int>m;
    for(int i=0;i<n;i++)
    m[arr[i]]++;
    for(auto i:m)
    {
        if(i.second>(n/2))
        return i.first;
    }
    return -1;
    */
    // moore's voting algorithm
    int c = 0, me;
    for (int i = 0; i < n; i++)
    {
        if (c == 0)
        {
            c = 1;
            me = arr[i];
        }
        else if (arr[i] == me)
            c++;
        else
            c--;
    }
    int c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (me == arr[i])
            c1++;
    }
    if (c1 > (n / 2))
        return me;
    else
        return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    int me = ans(arr, n);
    cout<<me;
    return 0;
}