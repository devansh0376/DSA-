#include<bits/stdc++.h>
using namespace std;
/*
 Given an array that contains both negative and positive integers, find the maximum product subarray.
Input: Nums = [1,2,-3,0,-4,-5]
Output:20
Explanation: In the given array, we can see (-4)×(-5) gives maximum product value.
*/
// brute force : using two loop.
int solve1(int arr[],int n)
{
    if(n==1)return arr[0];
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int m=1;
        for(int j=i;j<n;j++)
        {
            m*=arr[j];
            ans=max(ans,m);
        }
    }
    return ans;
}
int solve2(int arr[],int n)
{
    int prefix=1,suffix=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix*=arr[i];
        suffix*=arr[n-i-1];
        ans=max(ans,max(prefix,suffix));
    }
    return ans;
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans1=solve1(arr,n);
    int ans2=solve2(arr,n);
    cout<<ans1<<endl;
    cout<<ans2<<endl;
 return 0;
}