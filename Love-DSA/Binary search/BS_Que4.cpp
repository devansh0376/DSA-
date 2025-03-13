#include<bits/stdc++.h>
using namespace std;
// binary search in rotate array
/*
i/p: 9 8                o/p: 3
     5 6 7 8 9 10 1 2 3
->here we first find pivot element (min element)...
->now we get two sorted array..apply binary search on both array.     
*/
int BS(int arr[],int l,int h,int k)
{
    int mid=(l+h)/2;
    while(l<=h)
    {
        if(arr[mid]==k)
        return mid;
        else if(k>arr[mid])
        l=mid+1;
        else
        h=mid-1;
        mid=(l+h)/2;
    }
    return -1;
}
int findmin(int arr[],int n)
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
    if(arr[0]<arr[n-1])
    return arr[0];
    int l=0,h=n-1;
    int mid=(h+l)/2;
    while(l<h)
    {
        if(arr[mid]>=arr[0])//we are on the first line
        l=mid+1;
        else
        h=mid;//we are on the second line
        mid=(h+l)/2;
    }
    return h;
}

int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    int pivot=findmin(arr,n);
    int a=BS(arr,pivot,n-1,k);
    int b=BS(arr,0,pivot-1,k);
    if(a==-1 && b!=-1)
    cout<<b;
    else if(a!=-1 && b==-1)
    cout<<a;
    else
    cout<<-1;
    
}   