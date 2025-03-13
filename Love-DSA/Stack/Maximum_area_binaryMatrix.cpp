#include<bits/stdc++.h>
using namespace std;
//Max area rectangle in binary matrix 
/*
i/p : 0 1 1 0  o/p : 8 
      1 1 1 1 
      1 1 1 1
      1 1 0 0 
->Here we have to find max area genrated by making rectangle in 2D matrix
->We break down this problem to MAH problem  
0 1 1 0 -> H1 vector ->we find MAH for all this h1,h2,h3 and h4 vector
1 1 1 1 -> H2 vector -> if 0 occures so we push 0 in vector.other wise push v[j]+arr[i]  
1 1 1 1 -> H3 vector
1 1 0 0 -> H4 vector    
*/
vector <int> NSR(vector<int>arr,int n)
{
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i=n-1;i>=0;i--)
    {
        while(s.size()!=0 && (s.top()).first>=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(n);
        else 
        v.push_back((s.top()).second);

        s.push({arr[i],i}); 
    }
    reverse(v.begin(),v.end());
    return v;
}
vector <int> NSL(vector<int>arr,int n)
{
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        while(s.size()!=0 && (s.top()).first>=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(-1);
        else 
        v.push_back((s.top()).second);

        s.push({arr[i],i});
    }
    return v;
}
int MAH(vector<int>arr,int n)
{
    vector<int>v1=NSR(arr,n);
    vector<int>v2=NSL(arr,n);
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int x=(v1[i]-v2[i]-1);
        mx=max(mx,x*arr[i]);
    }
    
    return mx;
}
int main() {
    int n,m;cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<int>v;
    for(int j=0;j<m;j++)
    v.push_back(arr[0][j]);
    int mx=MAH(v,m);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            v[j]=0;
            else
            v[j]+=arr[i][j];
        }
        mx=max(mx,MAH(v,m));
        //for(auto i:v)cout<<i<<" ";cout<<endl;
    }
    cout<<mx;
 return 0;
}