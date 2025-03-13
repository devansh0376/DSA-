#include<bits/stdc++.h>
using namespace std;
/*
Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.
A subarray is a contiguous non-empty sequence of elements within an array.
Input Format: N = 3, array[] = {1,2,3}, k = 3
output: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
*/
int subarray_count(int arr[],int n,int k)
{
    unordered_map<int,int>m;
    int s=0,c=0;
    m[0]=1;
    for(int i=0;i<n;i++)
    {
        s+=arr[i];
        int rem=s-k;
        c+=m[rem];
        m[s]++;
    }
    return c;
}           
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans=subarray_count(arr,n,k);
    cout<<ans;
 return 0;
}