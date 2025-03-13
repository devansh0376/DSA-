#include<bits/stdc++.h>
using namespace std;
// print the number of times sorted array is rotated or
// find the index of the minimum element(pivot element)
/*
i/p : 11 12 15 18 2 5 6 8 } -> 2 5 6 8 11 12 15 18
o/p : 4                   } -> we got this array by 4 time rotate : 11 12 15 18 2 5 6 8 
-> find peak elemenet (arr[i-1]< arr[i] > arr[i+1]  : arr[i]->peak element)
*/
// 0(N) solution
int ans1(int arr[], int n)
{
    if(n==1)
    return 0;
    if(n==2)
    {
        if(arr[0]>arr[1])
        return 1;
        else
        return 0;
    }
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]<arr[0])
        return n-i;
    }
    if(arr[0]>arr[n-1])
    return n-1;
    else
    return 0;
}
//0(log n) solution using binary search
/*
-> there are two lines 1> 11 12 13 18 and 2> 2 5 6 8.we want to find second line's first element index..first and second line are in incresing ordered. Aim is going towards second line..
->so we find mid element..if it is greater than arr[0] then we are on first line so we do l=mid+1. If mid element is less than first element so we are on second line and we do h=m(if we do h=m-1..so we goes to first line)
-> at the end the h and l are pointing to the same index it is our peak(min) element.. and it is represent the how many time we rotate the sorted array
*/
int ans2(int arr[],int n)
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
    int ans;
    while(l<h)
    {
        if(arr[mid]>=arr[0])// we are on first line so we do l=mid+1
        l=mid+1,ans=mid;
        else
        h=mid;//we are on second line and we do h=m(if we do h=m-1..so we goes to first line)
        mid=(l+h)/2;
    } 
    if(arr[0]<arr[n-1])
	return arr[0];//0
	else
    return n-h;// or return l;
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<ans1(arr,n);
 return 0;
}