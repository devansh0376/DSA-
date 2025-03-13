#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement: Given an array of integers arr[] and an integer target.
1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.
*/
// we use soncept of prefix sum and hashing
vector<pair<int,int> >solve(int arr[],int n,int k)
{
    map<int,int>m;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int x=k-arr[i];
        if(m.find(x)!=m.end())
        v.push_back({m[x],i});
        m[arr[i]]=i;
    }
    return v;
}      
//this code can apply when they ask for first varient.Bcoz in this array must sort and if we sort array index are no match with previous index.
vector<pair<int,int>> solve1(int arr[],int n,int k)
{

    sort(arr,arr+n);
    int l=0,h=n-1;
    vector<pair<int,int>>v;
    while(l<h)
    {
        if(arr[l]+arr[h]==k)
        {
            v.push_back({l,h});
            return v;
        }
        else if(k>arr[l]+arr[h])
        l++;
        else
        h--;
    }
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<pair<int,int>>v=solve1(arr,n,k);
    for(auto i:v)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
 return 0;
}