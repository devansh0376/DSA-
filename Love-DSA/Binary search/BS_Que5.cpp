#include<bits/stdc++.h>
using namespace std;
// search in nearly sorted array 
/*
i/p: 5 10 30 20 40 , k=20
o/p: 3
-> if any element in sorted array have index i. so in nearly sorted array it index may be i or i+1 or i-1
nearly sorted : 5 10 30  20 40
                       /\
sorted array  : 5 10 20  30 40
->in simple binary search we do l/h=m-1,m,m+1 but here we should do l/h= m-2,m,m+2 (m=(h+l)/2) and in simple binarysearch we check mid , here we should check mid,mid-1 and mid+1
*/
int BS_in_NSA(int arr[],int n,int k)
{
    int l=0,h=n-1;
    int mid=(l+h)/2;
    while(l<=h)
    {
        if(arr[mid]==k)
        return mid;
        else if(arr[mid-1]==k && mid-1>=l)
        return mid-1;
        else if(arr[mid+1]==k && mid+1<=h)
        return mid+1;
        else if(k>arr[mid])
        l=mid+2;
        else
        h=mid-2;
        mid=(l+h)/2;
    }
    return -1;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<BS_in_NSA(arr,n,k);
 return 0;
}