#include<bits/stdc++.h>
using namespace std;
/*
Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k
*/
// we use two pointer approch and use such logic such that no dublicate terms will count
vector<vector<int>> solve(int arr[],int n)
{
    sort(arr,arr+n);
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        //if(i>0 && arr[i]==arr[i-1])continue;
        if(i==0 ||arr[i]!=arr[i-1])
        {
            int l=i+1,h=n-1;
            //int sum=-(arr[i]); // sum=-a and l=b and h=c
            while(l<h) 
            {
                int sum=arr[i]+arr[l]+arr[h];
                if(sum==0)
                {
                    vector<int>t;
                    t.push_back(arr[i]);
                    t.push_back(arr[l]);
                    t.push_back(arr[h]);
                    ans.push_back(t);
                    while(l<h&&arr[l]==arr[l+1])l++;
                    while(l<h && arr[h]==arr[h-1])h--;
                    l++;h--;
                }
                else if(sum<0)
                l++;
                else 
                h--;
            }
        }
    }   
    return ans;
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<vector<int>> ans=solve(arr,n);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
 return 0;
}