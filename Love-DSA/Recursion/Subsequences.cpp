#include <bits/stdc++.h>
using namespace std;
/*
[1,2,3] :[ {} {1} {2} {3} {1,2} {1,3} {2,3} {1,2,3} ]
___,1__,_2_,__3,12_,
*/
void solve(string s,int n,vector<string>&ans,string temp,int i)
  {
      if(i==n)
      {
          if(temp.size()>0)
          ans.push_back(temp);
          return;
      }
      //take
      solve(s,n,ans,temp+s[i],i+1);
      //not take
      solve(s,n,ans,temp,i+1);
  }
int main() {
    int n;cin>>n;
    string s;cin>>s;
    vector<string>ans;
    string temp="";
    solve(s,n,ans,temp,0);
    for(auto i:ans)
    cout<<i<<endl;
}