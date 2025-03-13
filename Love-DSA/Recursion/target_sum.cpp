#include<bits/stdc++.h>
using namespace std;
/*
->print all subsequences whose sum is k
arr[]=[1,2,1],k=2
[{1,1}{2}{1,1}]
*/
/*
bool solve(int arr[],int n,int k,int i,int sum,vector<int>&ans)
{
    if(i==n)
    {
        if(sum==k)
        {
            for(auto i:ans)
            cout<<i<<" ";
            cout<<endl;
            return true;
        }
        else
        return false;
    }
    ans.push_back(arr[i]);
    sum+=arr[i];

    if(solve(arr,n,k,i+1,sum,ans)==true)
    return true;

    sum-=arr[i];
    ans.pop_back();

    if(solve(arr,n,k,i+1,sum,ans)==true)
    return true;
    return false;
}*/
void solve(int arr[],int n,int k,int i,int sum,vector<int>&ans)
{
    if(i==n)
    {
        if(sum==k)
        {
            for(auto i:ans)
            cout<<i<<" ";
            cout<<endl;
        }
        return;
    }
    ans.push_back(arr[i]);
    //sum+=arr[i];

    solve(arr,n,k,i+1,sum+=arr[i],ans);

    //sum-=arr[i];
    ans.pop_back();

    solve(arr,n,k,i+1,sum-=arr[i],ans);
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)
    cin>>i;
    vector<int>ans;
    solve(arr,n,k,0,0,ans);
 return 0;
}