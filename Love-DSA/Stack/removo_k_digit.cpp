#include<bits/stdc++.h>
using namespace std;
/*
->Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.
S = "149811", K = 3
Output: 111
Explanation: Remove the three digits    
4, 9, and 8 to form the new number 111
which is smallest.
Input:
S = "1002991", K = 3
Output: 21
*/
//for make smaller number we should erase the numbers from left to right.
// approch 1 : we track the peak element(greter than previous elment).when s[i]>s[i-1].so we remove the s[i].and decrese out k value
string ans1(string s,int k)
{
    int n=s.size();
    //for without zero valid string
    while(k>0)
    {
        int i=1;
        while(i<n && s[i]>=s[i-1])
        i++;
        s.erase(i-1,1); // 149811. first peak ele. is 9..so we remove it.
        k--;
    }
    //for trim zero at begining
    int i=0; // in ex 2: ans is 0021. so we should erase zero at begining
    while(i<s.size()-1 && s[i]=='0')
    i++;
    s.erase(0,i); 
    return s==""?"0":s;
}
// apporch 2 : using stack
/*
->we push element in stack is if stack is not empty or s[i]!='0'
->if s[i]<st.top() => we s.pop()
*/
string ans2(string s,int k)
{
    stack<char>st;
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        while(st.size() >0 && st.top()>s[i])
        {
            st.pop();
            k--;
        }
        if(st.size()>0 || s[i]!=0)
        st.push(s[i]);
    }
    while(k>0 && st.size()>0)
    {
        st.pop();
        k--;
    }
    if(st.size()==0)
    return "0";
    while(st.size()>0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    string s;cin>>s;
    int k;cin>>k;
    string s1=ans1(s,k);
    string s2=ans1(s,k);
    cout<<s1<<endl;
    cout<<s2<<endl;
 return 0;
}