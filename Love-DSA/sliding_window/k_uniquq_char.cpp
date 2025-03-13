#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
//Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters.
/*
Input:
S = "aba", K = 2    
Output:
3
Explanation: The substrings are: "ab", "ba" and "aba".
*/
/*
x+y<z -> y<z :-> here if a b a < 3 so a b,b a,a b a all substring is less than 3.so there for we add full lenght of window(Subaray).but we count one calculation double time like : aba => we first count ab and then we count for ab,ba,aba but we need only for ba and aba .
so we need to remove this reduntant calculations
and we call this function two time one for k and other for k-1.
k 2 : a b a | k 2 - k 1
k 1 : a     | a b a - a = 2 and we want calculation for 2
*/
long long atmostK1(string &s, int k)
{
    unordered_map<char, long long> m;
    long long n = s.size();
    long long i = 0, j = 0, ans = 0;
    while (j < n)
    {
        m[s[j]]++;
        while (m.size() > k)
        {
            m[s[i]]--;
            if (m[s[i]] == 0)
                m.erase(s[i]);
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    return ans;
}
long long atmostK2(string &s, int k)
{
    // unordered_map<char,long long> m;
    vector<int> m(26, 0);
    long long n = s.size();
    long long i = 0, j = 0, ans = 0, disting = 0;
    while (j < n)
    {
        if (m[s[j] - 'a'] == 0)
            disting++;
        m[s[j] - 'a']++;
        while (disting > k)
        {
            m[s[i] - 'a']--;
            if (m[s[i] - 'a'] == 0)
                disting--;
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    return ans;
}
long long int substrCount(string s, int k)
{
    // code here.
    //  return atmostK1(s,k)-atmostK1(s,k-1);
    return atmostK2(s, k) - atmostK2(s, k - 1);
}
int main()
{
    return 0;
}