#include<bits/stdc++.h>
using namespace std;
/*
 Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.
 Input Format: A = [4, 2, 2, 6, 4] , k = 6
Result: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
*/
// brute force: generate all subarray and check for xor of subarray is equal to k
// better sollution : run two loop 
int solve1(int arr[],int n,int k)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        int x=0;
        for(int j=i;j<n;j++)
        {
            x^=arr[j];
            if(x==k)
            c++;
        }
    }
    return c;
}
//optimal solution : we use concept of prefix xor and hashing
/*
   x  k  xr
 __|__|__|__  -> till here xor of all element if xr. we assume that there is x and k, such that
  x^k=xr -> x^k^k=xr^k -> x=xr^k; we have to find x.if there is x so there always subarray which xor is equqal to k.

*/
int solve2(int arr[],int n,int k)
{
    int c=0,xr=0;
    map<int,int>m;
    m[0]=1;
    for(int i=0;i<n;i++)
    {
        xr=xr^arr[i];
        int x=xr^k;
        c+=m[x];
        m[xr]++;
    }
    return c;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans1=solve1(arr,n,k);
    cout<<ans1<<endl;
    int ans2=solve2(arr,n,k);
    cout<<ans2<<endl;
 return 0;
}