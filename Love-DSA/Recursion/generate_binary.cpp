#include <bits/stdc++.h>
using namespace std;
void solve(int n,vector<string>&ans,string temp,int i)
{
    if(i==n)
    {
        
        //for with out consicutive one's binary string
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='1' && temp[i+1]=='1')
            return;
        }
        ans.push_back(temp);
        
       //ans.push_back(temp);
        return;
    }
    //take
    solve(n,ans,temp+"0",i+1);
    //not take
    solve(n,ans,temp+"1",i+1);
}
int main() {
    int n;cin>>n;
    string temp="";
    vector<string>ans;
    solve(n,ans,temp,0);
    for(auto i:ans)
    cout<<i<<endl;
}