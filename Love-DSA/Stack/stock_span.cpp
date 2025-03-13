#include<bits/stdc++.h>
using namespace std;
//stoke span problem : count consicutive smaller elements to left
/*
EX : i/p :100 80 60 70 60 75 85
     o/p : 1  1  1  2  1  4   6
-> so here we want to stop when the element is greter than current element and count the no. ele befor we stop
-> So we use NGE to left consept
-> if we want to count how many step , minus the index of orignal array minus NGEL array
-> for the track the index we make pair of index and element( stack<pair<element,index) )
*/
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    stack<pair<int,int>>s;
    vector<int>index;
    for(int i=0;i<n;i++)
    {
        while(s.size()!=0 && (s.top()).first<=arr[i])
        s.pop();
        if(s.size()==0)
        index.push_back(-1);
        else
        index.push_back((s.top()).second);

        s.push({arr[i],i});
    }
    vector<int>ans;
    for(int i=0;i<n;i++)
    ans.push_back(i-index[i]);

    for(auto i:ans)cout<<i<<" ";
 return 0;
}