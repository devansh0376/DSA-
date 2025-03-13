#include <bits/stdc++.h>
using namespace std;
void solve(int n,vector<string>&ans,string temp,int start,int end,int i)
{
    if(i==2*n)
    {
        ans.push_back(temp);
        return;
    }
    if(start<n)
    solve(n,ans,temp+"(",start+1,end,i+1);
    if(end<start)
    solve(n,ans,temp+")",start,end+1,i+1);
}
int main() {
    int n;cin>>n;
    vector<string>ans;
    int start=0,end=0;
    string temp="";
    solve(n,ans,temp,start,end,0);
    for(auto i:ans)
    cout<<i<<endl;
}