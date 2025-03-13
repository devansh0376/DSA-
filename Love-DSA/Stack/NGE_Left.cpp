#include <bits/stdc++.h>
using namespace std;
//Nearest greater element to left(Next greater element)
/*
if they ask ..Nearest smaller to left..so simple 
trvers like this code but condion in while loop like : s.top()>=arr[i]
->if they aks to use array as cicular..just replace i by i%n (n=2*n-1)
*/
int main() 
{
    vector<int>v;
    stack<int>s;
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    for(int i=0;i<n;i++)
    {
        while(s.size()!=0 && s.top()<=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(-1);
        else
        v.push_back(s.top());
        s.push(arr[i]);
    }
    for(auto i:v)cout<<i<<" ";
    return 0;
}