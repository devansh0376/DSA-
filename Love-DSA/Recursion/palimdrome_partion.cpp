#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool is_palimdrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void solve(int idx, string s, vector<string> &temp, vector<vector<string>> &ans)
{
    if (idx == s.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        if (is_palimdrome(s, idx, i))
        {
            temp.push_back(s.substr(idx, i - idx + 1));
            solve(i + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}
int main()
{
    string s;
    cin >> s;
    vector<string> temp;
    vector<vector<string>> ans;
    solve(0, s, temp, ans);
    for(auto i:ans)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}