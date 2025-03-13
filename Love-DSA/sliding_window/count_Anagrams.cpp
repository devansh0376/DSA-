#include <bits/stdc++.h>
using namespace std;
/*
Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.
Example 1:
Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears in the txt, hence answer is 3.
txt = aabaabaa
pat = aaba
Output: 3 
*/
int ans(string s, string b)
{
    // code here
    int n = s.size(), k = b.size();
    map<char, int> m;
    for (int i = 0; i < k; i++)
        m[b[i]]++;
    int cnt = m.size(), ans = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        // calculation
        char ch = s[j];
        if (m.find(ch) != m.end())
        {
            m[ch]--;
            if (m[s[j]] == 0)
                cnt--;
        }    

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            // operation and ans
            if (cnt == 0)
                ans++;
            // reverse process.when char..if found in map we do cnt--. check if m[s[i]]==0 -> cnt--, here we do revrese of this
 
            if (m.find(s[i]) != m.end())
            {
                m[s[i]]++;
                if (m[s[i]] == 1)
                    cnt++;
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string s,b;cin>>s>>b;
    cout<<ans(s,b);
    return 0;
}