#include<bits/stdc++.h>
using namespace std;
//Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically(sorted ordered) next greater permutation of numbers.
/*
Input format: Arr[] = {1,3,2}
Output: Arr[] = {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,1,3} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
*/
//brute force : find all permutation and then search
void findpermutation(int index,vector<int> arr,int n,vector<vector<int>>&ans)
{
    if(index==n)
    {
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<n;i++)
    {
        swap(arr[index],arr[i]);
        findpermutation(index+1,arr,n,ans);
        swap(arr[index],arr[i]);
    }
}
int main() {
    int n;cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        arr.push_back(x);
    }
    /*
    vector<vector<int>>ans;
    findpermutation(0,arr,n,ans);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    */
   //c++ built in function
   next_permutation(arr.begin(),arr.end());
   for(auto i:arr)cout<<i<<" ";cout<<endl;
   //implimantion of next_permutation() function
   /*
   // we have to find just greater than permutation given permutation
    s1> find break point : a[i]<a[i+1]
    s2> find ele > a[i], but the smallest one. so you will stay closer
    s3>append other element as sorted orderd.
    ex : 2 1 5 4 3 0 0
         2 1 | 5 4 3 0 0 -> 1 3 | 5 4 3 1 0 -> 1 3 0 1 3 4 5(ans)
   */
  int idx=-1;
  //find break point
  for(int i=n-1;i>=0;i--)
  {
    if(arr[i]<arr[i+1])
    {
        idx=i;
        break;
    }
  }
  // T.C : 0(3*n)= 0(n)
  // find first greter element
  for(int i=n-1;i>=idx;i--)
  {
    if(arr[i]>arr[idx])
    {
        swap(arr[i],arr[idx]);
        break;
    }
  }
  // sort the remaining element
  reverse(arr.begin()+idx+1,arr.end());
   for(auto i:arr)cout<<i<<" ";cout<<endl;
 return 0;
}
