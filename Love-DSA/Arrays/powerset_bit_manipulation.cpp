#include <bits/stdc++.h>
using namespace std;
// for array
vector<vector<int>> subsets(int arr[],int n)
{
    // int n=arr.size();
    /*
    vector<vector<int>>ans;
    vector<int>temp;
    solve(arr,n,0,temp,ans);
    return ans;
    */
    vector<vector<int>> ans;
    int m = 1 << n;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                v.push_back(arr[j]);
        }
        ans.push_back(v);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
// for string
vector<string> AllPossibleStrings(string s)
{
    // Code here
    // int n=s.size();
    /*
    vector<string>ans;
    string temp="";
    solve(s,n,0,temp,ans);
    sort(ans.begin(),ans.end());
    return ans;
    */
    int n = s.size();
    vector<string> ans;
    int m = 1 << n;
    for (int i = 1; i < m; i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                temp += s[j];
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    string s;cin>>s;
    vector<vector<int>>ans1=subsets(arr,n);
    vector<string>ans2=AllPossibleStrings(s);
    cout<<"subsets for array : "<<endl;
    for(auto i:ans1)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"subsets for string : "<<endl;
    for(auto i:ans2)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
   return 0;
}