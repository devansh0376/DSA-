#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
*/
/*
-> in this question we sum all max element and sum all min element then return max-min
*/
//for sum of min elements
vector<int> NSER(int arr[],int n)
{
    vector<int> v;
    stack<pair<int,int>>s;
    for(int i=n-1;i>=0;i--)
    {
        while(s.size()>0 && (s.top().first)>arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(n);
        else 
        v.push_back((s.top().second));

        s.push({arr[i],i});
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        v[i]=v[i]-i;
    }
    return v;
}
vector<int> NSEL(int arr[],int n)
{
    vector<int> v;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        while(s.size()>0 && (s.top().first)>=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(-1);
        else 
        v.push_back((s.top().second));

        s.push({arr[i],i});
    }
    for(int i=0;i<n;i++)
    {
        v[i]=i-v[i];
    }
    return v;
}
//for sum of max elements
vector<int> NGER(int arr[],int n)
{
    vector<int> v;
    stack<pair<int,int>>s;
    for(int i=n-1;i>=0;i--)
    {
        while(s.size()>0 && (s.top().first)<arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(n);
        else 
        v.push_back((s.top().second));

        s.push({arr[i],i});
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        v[i]=v[i]-i;
    }
    return v;
}
vector<int> NGEL(int arr[],int n)
{
    vector<int> v;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        while(s.size()>0 && (s.top().first)<=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(-1);
        else 
        v.push_back((s.top().second));

        s.push({arr[i],i});
    }
    for(int i=0;i<n;i++)
    {
        v[i]=i-v[i];
    }
    return v;
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int> v1=NSER(arr,n);
    vector<int> v2=NSEL(arr,n);
    int mn=0;
    for(int i=0;i<n;i++)
    {
        mn+=arr[i]*v1[i]*v2[i];
    }
    vector<int> v3=NGER(arr,n);
    vector<int> v4=NGEL(arr,n);
    int mx=0;
    for(int i=0;i<n;i++)
    {
        mx+=arr[i]*v3[i]*v4[i];
    }
    cout<<mx-mn<<endl;
 return 0;
}