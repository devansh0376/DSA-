#include<bits/stdc++.h>
using namespace std;
// generate subsets 
/*
i/p:1 2 3
o/p: [ {} {1} {2} {3} {1,2} {1,3} {2,3} {1,2,3} ]
total subset is : 2^n 2^3=8
base condition : once a index >= size then store result . one recursion is complete
*/
void subset(int arr[],int n,int i,vector<int>&ans)
{
    if(i>=n)
    {
        for(auto i:ans)
        cout<<i<<" ";
        if(ans.size()==0)
        cout<<"{}";
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);
    subset(arr,n,i+1,ans);//take
    ans.pop_back();//remove element
    subset(arr,n,i+1,ans);//not take
}
//for return
void solve(vector<int>arr,int n,int i,vector<int>temp,vector<vector<int>>&ans)
{
    if(i>=n)
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    solve(arr,n,i+1,temp,ans);//take
    temp.pop_back();
    solve(arr,n,i+1,temp,ans);//not take
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)
    cin>>i;
    vector<int>ans;
    subset(arr,n,0,ans);
 return 0;
}