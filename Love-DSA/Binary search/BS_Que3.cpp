#include<bits/stdc++.h>
using namespace std;
// input must be like : 7 8 15 3 2 1 or 11 12 13 22 8 5 2 1
// find peak(minimum element) -? arr[i]>arr[i-1] and arr[i]>arr[i+1]
//0(N) sollution
int ans1(int arr[],int n)
{
      if(n==1)
       return 0;
       if(n==2)
       {
           if(arr[0]>arr[1])
           return 0;
           else
           return 1;
       }
       for(int i=1;i<n-1;i++)
       {
           if(arr[i]>=arr[i-1] && arr[i] >=arr[i+1])
           return i;
       }
       if(arr[0]>arr[n-1])
       return 0;
       else
       return n-1;
}
//if mid element is not peak element so we have to decide where should we go right or left
/*
->if(arr[mid]>arr[mid-1]) : so arr[mid-1] nevere be a peak element bcoz peak element is bigger than arr[m-1] and arr[m+1] so we go for right.
->if(arr[mid]>arr[mid+1]) : so arr[mid+1] nevere be a peak element bcoz peak element is bigger than arr[m-1] and arr[m+1] so we go for left.
-> insort arr[mid+1] is big so we go for right and arr[mid-1] is big so we go for left
line 1 :11 12 13 22         22
line 2 : 8 5 2 1           /  \
                   11 12 13     8 5 2 1
*/
int ans2(int arr[],int n)
{
    if(n==1)
    return 0;
   int l=0,h=n-1,mid=(l+h)/2;
   while(l<=h)
   {
    if(mid>0 && mid<n-1)
    {
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        return mid;
        else if(arr[mid+1]>arr[mid]) 
        l=mid+1;
        else if(arr[mid-1]>arr[mid]) 
        h=mid-1;
    }
    else if(mid==0)
    {
        if(arr[mid]>arr[mid+1])
        return 0;//mid
        else 
        return 1;//mid+1
    }
    else if(mid==n-1)
    {
        if(arr[mid]>arr[mid-1])
        return n-1;//mid
        else
        return n-2;//mid-1
    }
    mid=(l+h)/2;
   }
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<ans2(arr,n);
 return 0;
}