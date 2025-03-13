#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    // first approch using two hash array
    /*          m1   m2
     s:abaab   a:x   x:a
     t:xyyxy   b:y   y:b
               a:y(we check that accournce of 'a' is zero of not. here 'a' is already present.so we check
                m1[s[i]]!=t[i](m1[a])!=y)
    */
    char m1[256] = {};
    char m2[256] = {};
    for (int i = 0; i < s.size(); i++)
    {
        if (m1[s[i]] == 0 && m2[t[i]] == 0)
        {
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        else if (m1[s[i]] != t[i])
        {
            cout << "false";
            break;
        }
    }
    cout << "true";
    // second approch using 1 hash array
    char hash[128] = {};
    for (int i = 0; i < s.size(); i++)
    {
        if (!hash[s[i]])
        {
            for (auto j : hash)
            {
                if (j == t[i])
                    cout << "false";
                return 0;
            }
            hash[s[i]] = t[i];
        }
        else
        {
            if (hash[s[i]] != t[i])
                cout << "false";
            return 0;
        }
    }
    cout << "true";
    return 0;
}