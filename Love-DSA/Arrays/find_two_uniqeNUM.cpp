#include <bits/stdc++.h>
using namespace std;
/*
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.
Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 
Explaination: 5 and 1 have odd occurrences.
*/
vector< int> twoOddNum( int arr[],int n)
{
    // code here
    /*
    unordered_map<ll,ll>m;
    vector<long long int>v;
    for(int i=0;i<n;i++)
    m[arr[i]]++;
    for(auto i:m)
    {
        if(i.second%2!=0)
        v.push_back(i.first);
    }
    return v;
    */
    int res1 = 0, res2 = 0, x = 0;
    for (int i = 0; i < n; i++)
        x ^= arr[i];
    // find right most set bit
    x = (x & (~(x - 1)));

    for (int i = 0; i < n; i++)
    {
        if (arr[i] & x)
            res1 ^= arr[i];
        else
            res2 ^= arr[i];
    }
    if (res1 > res2)
        return {res1, res2};
    else
        return {res2, res1};
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int>v=twoOddNum(arr,n);
    cout<<v[0]<<" "<<v[1];
    return 0;
}