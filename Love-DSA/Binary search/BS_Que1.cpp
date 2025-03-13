#include <bits/stdc++.h>
using namespace std;
// fisrt and last occurance of element
/*
->here we make two function . first for left occurance and second for right occurance
*/
/*
1) count the number of occurance in sorted array 
->simple ...return last_occurance-first_occurance+1
*/
int first_occurance(int arr[],int n,int k)
{
    int l=0,h=n-1;
    int mid=(l+h)/2;
    int ans=-1;
    while(l<=h)
    {
        if(arr[mid]==k)
        {
            ans=mid;
            h=mid-1;
        }
        else if(k>arr[mid])
        l=mid+1;
        else
        h=mid-1;
        mid=(l+h)/2;
    }

    return ans;
}
int last_occurance(int arr[],int n,int k)
{
    int l=0,h=n-1;
    int mid=(l+h)/2;
    int ans=-1;
    while(l<=h)
    {
        if(arr[mid]==k)
        {
            ans=mid;
            l=mid+1;
        }
        else if(k>arr[mid])
        l=mid+1;
        else
        h=mid-1;
        mid=(l+h)/2;
    }

    return ans;
}
int main() 
{
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int f=first_occurance(arr,n,k);
    int l=last_occurance(arr,n,k);
    cout<<f<<" "<<l<<endl;
 return 0;
}