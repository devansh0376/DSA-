#include<bits/stdc++.h>
using namespace std;
// Allocate minimum number of pages
/*
->we have to distribute book contingoes manner among k student such that every student get book and no book is left
->maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.
*/
// aggresive cows
/*
//brute force
bool valid1(vector<int>arr,int d,int k)
{
    int n=arr.size();
    int x=arr[0];
    k--;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-x>=d)
        {
            k--;
            if(k==0)
            return true;
            x=arr[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int k) {
  //    Write your code here.
  int n = arr.size();
  int ans = 0;
  sort(arr.begin(),arr.end());
  int max_d=arr[n-1]-arr[0];
  for(int i=1;i<=max_d;i++)
  {
      if(valid1(arr,i,k))
      {
          ans=max(ans,i);
      }
  }
  return ans;
}
//using binary search
bool valid(vector<int>arr,int n,int k,int min_dist)
{
    int cnt=1;
    int x=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-x>=min_dist)
        {
            cnt++;
            x=arr[i];
        }
        if(cnt==k)
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(),arr.end());
     //min dist posssible is 1 low=1,and max dist possible is we place one cow at 0 and athore at n-1 ,high=arr[n-1]-arr[0]    
    int h=arr[n-1]-arr[0],l=1;
    int ans=-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(valid(arr,n,k,mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        h=mid-1;
    }
    return ans;
}
*/
// using binary search
bool valid(int arr[],int n,int k,int max_pages)
{
    int pages=0,student=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_pages)
        return false;
        if(arr[i]+pages>max_pages)
        {
            student++;
            pages=arr[i];
        }
        else
        pages+=arr[i];
        if(student>k)
        return false;
    }
    return true;
}
int findpages(int arr[],int n,int k)
{
    if(n<k)return -1;
    int l=0,ans=-1;
    int h=accumulate(arr,arr+n,0);
    int mid=(l+h)/2;
    while(l<=h)
    {
        if(valid(arr,n,k,mid))
        {
            ans=mid;
            h=mid-1;
        }
        else
        l=mid+1;
        mid=(l+h)/2;
    }
    return ans;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int min_pages=findpages(arr,n,k);
    cout<<min_pages;
 return 0;
}