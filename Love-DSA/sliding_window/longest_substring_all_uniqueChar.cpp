#include <bits/stdc++.h>
using namespace std;
/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/
int ans(string s)
{
    // code
    int n = s.size();
    // all unique character
    int i = 0, j = 0, mx = 0;
    unordered_map<char, int> m;
    int k = 0;
    while (j < n)
    {
        // calculation
        m[s[j]]++;
        if (m.size() == j - i + 1)
        {
            // store ans
            mx = max(mx, j - i + 1);
            j++;
        }
        else
        {
            // remove calculation
            while (m.size() >= 1 && m.size() < j - i + 1) // number of unique charater is less than window size
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return mx;
}
int ans2(string s)
{
    int n=s.size();
    int i=0,j=0;
    int mx=INT_MIN;
    //unordered_map<char,int>m;
    vector<int>m(256,-1);
    while(j<n)
    {
        if(m[s[j]]!=-1)
        i=max(m[s[j]]+1,i);
        m[s[j]]=j;
        mx=max(mx,j-i+1);
        j++;
    }
    return mx;
}
int main()
{
    string s;cin>>s;
    cout<<ans(s)<<endl;
    cout<<ans2(s);
    return 0;
}