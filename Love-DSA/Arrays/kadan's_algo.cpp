#include<bits/stdc++.h>
using namespace std;
//kadan's algorithm
/*
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum. 
Input:N = 5,Arr[] = {1,2,3,-2,5}
Output:9
Explanation:Max subarray sum is 9of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
*/
int main() 
{
    int n;cin>>n;
    int arr[n];cin>>n;
    for(auto &i:arr)cin>>i;
    int sum=0,mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        mx=max(sum,mx);
        if(sum<0)
        sum=0;
    }
    cout<<sum;
 return 0;
}