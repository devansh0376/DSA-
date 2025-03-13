#include<bits/stdc++.h>
using namespace std;
// search in bitonic array(mountain  array)
int find_peak(int arr[],int n)
{
    if(n==0)
    return 0;
    if(n==2)
    {
	    if(arr[0]<arr[1])
	    return 0;
	    else
	    return 1;
    }
    int l=0,h=n-1;
    int mid=(l+h)/2;
    while(l<h)
    {
        if(arr[mid]>=arr[0])
        l=mid+1;
        else
        h=mid;
        mid=(l+h)/2;
    } 
    if(arr[0]<arr[n-1])
	return arr[0];
	else
    return arr[h];// or return l;
}
int BS(int arr[],int n,int k,int p)
{
    int l=0,h=p-1;
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
int RBS(int arr[],int n,int k,int p)
{
    int l=p,h=n-1;
    int mid=(l+h)/2;
    while(l<=h)
    {
        if(arr[mid]==k)
        return mid;
        if(k<arr[mid])
        l=mid+1;
        else 
        h=mid-1;

        mid=(l+h)/2;
    }
    return -1;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int peak=find_peak(arr,n);
    int x=BS(arr,n,k,peak);
    int y=RBS(arr,n,k,peak);

    if(x>y)
    cout<<x;
    else
    cout<<y;
 return 0;
}