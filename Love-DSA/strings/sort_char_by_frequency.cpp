#include <bits/stdc++.h>
using namespace std;
/*
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/
int main() {
    string s;cin>>s;
    map<char,int>m;
    for(int i=0;i<s.size();i++)
    m[s[i]]++;
    /*
    ->first approch using hashing and priority queue.
    ->TC=0(N*log(N)) SC=0(N)
    */
    priority_queue<pair<int,char>>p;
    for(auto i:m)
    p.push({i.second,i.first});
    string ans="";
    while(!p.empty())
    {
        auto x=p.top();
        //cout<<x.first<<" "<<x.second <<endl;
        p.pop();
        ans+=string(x.first,x.second);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    /*
    ->second approch: using hashing + bucket sort +counting
    ->TC=0(N) SC=0(N)
    */
    vector<string>v(s.size()+1,"");
    for(auto i:m)
    v[i.second].append(i.second,i.first);
    string ans1="";
    for(int i=s.size();i>=1;i--)
    {
        if(!v[i].empty())
        ans1+=v[i];
    }
    cout<<ans1;

}
/*
//Sorting Elements of an Array by Frequency. Given an array arr[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.
int main() {
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(auto &i:arr)cin>>i;
        map<int,int>m;
        for(int i=0;i<n;i++)m[arr[i]]++;
        vector<pair<int,int>>p;
        for(auto i:m)
        p.push_back({i.first,i.second});
        auto cmp=[](pair<int,int>p1,pair<int,int>p2)
        {
            if(p1.second==p2.second)
            return p1.first<p2.first;
            else
            return p1.second>p2.second;
        };
        sort(p.begin(),p.end(),cmp);
        for(auto i:p)
        {
            while(i.second--)
            cout<<i.first<<" ";
        }
        cout<<endl;
    }
}
*/