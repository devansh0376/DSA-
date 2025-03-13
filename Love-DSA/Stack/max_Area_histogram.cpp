#include<bits/stdc++.h>
using namespace std;
//Max area Histogram(MAH) 
/*
->Input array denotes the height of the building and we have to span the building and return max area by sapning buildng
-> A building can be sapn into other building when other building's (height >= current bulding's height)
-> so here we have to find NSL and NSR . width=NSL-NSR, area=width*arr[i].
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/
vector <int> NSR(int arr[],int n)
{
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i=n-1;i>=0;i--)
    {
        while(s.size()!=0 && (s.top()).first>=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(n);
        else 
        v.push_back((s.top()).second);

        s.push({arr[i],i}); 
    }
    reverse(v.begin(),v.end());
    return v;
}
vector <int> NSL(int arr[],int n)
{
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        while(s.size()!=0 && (s.top()).first>=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(-1);
        else 
        v.push_back((s.top()).second);
        s.push({arr[i],i});
    }
    return v;
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int>v1=NSR(arr,n);
    vector<int>v2=NSL(arr,n);
    for(auto i:v1)cout<<i<<" ";
    cout<<endl;
    for(auto i:v2)cout<<i<<" ";
    cout<<endl;
    int mx=INT_MIN;
   /* for(int i=0;i<n;i++)
    {
        int x=(v1[i]-v2[i]-1);//width
        mx=max(mx,x*arr[i]);
    }*/
    vector<int>width;
    for(int i=0;i<n;i++)
    {
        width.push_back(v1[i]-v2[i]-1);
    }
    for(int i=0;i<n;i++)
    {
        mx=max(mx,arr[i]*width[i]);
    }
    cout<<mx;
 return 0;
}