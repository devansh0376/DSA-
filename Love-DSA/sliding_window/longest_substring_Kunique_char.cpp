#include<bits/stdc++.h>
using namespace std;
//longest substring with k unique characters.
/*
i/p : s: aabacebebebe , k=3
o/p : 7 (cebebebe - > c,e,b unique charecter)
*/
// approch 1 : generate all substring and check if count of unique char is k or not.
//approch 2 : using variable size sliding window concept
int ans1(string s,int k)
{
    int n=s.size();
    int i=0,j=0,mx=0;
    unordered_map<char,int> m;
    while(j<n)
    {
        //calculation
        m[s[j]]++;
        if(m.size()<k)
        j++;
        else if(m.size()==k)
        {
            // store ans
            mx=max(mx,j-i+1);
            j++;
        }
        else if(m.size()>k)
        {
            //remove previous calculation
            while(m.size()>k)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;    
            }
            j++;   
        }
    }
    return mx;
}
int main() {
    string s;cin>>s;
    int k;cin>>k;
    cout<<ans1(s,k);
 return 0;
}