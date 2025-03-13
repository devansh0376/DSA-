#include<bits/stdc++.h>
using namespace std;
int ans(int arr[],int n,int k)
{
    int l=0,h=n-1;
    int mid=(l+h)/2;
    while(l<=h)
    {
        if(arr[mid]==k)
        return mid;
        if(k>arr[mid])
        l=mid+1;
        else if(k<arr[mid])
        h=mid-1;

        mid=(l+h)/2;
    }
    return -1;
}
int solve(int arr[],int n,int k,int l,int h)
{
    int mid=(l+h)/2;
    if(arr[mid]==k)
    return mid;
    else if(k>arr[mid])
    return solve(arr,n,k,mid+1,h);
    else 
    return solve(arr,n,k,l,mid-1);
    return -1;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int num=solve(arr,n,k,0,n-1);
    if(num!=-1)
    cout<<arr[num]<<" index is "<<num;
    else
    cout<<num;
 return 0;
}