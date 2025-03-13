#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2 Output: [1,2]
in brute force we have to make another map or vector<pair>
-here we have to sort base on frequency. compress problem into k largest element : make min heap
-make map count frequncy then make pair of min heap fisrt element freqency and second element is array element
*/
int k_frequnt_ele(int arr[],int n,int k)
{
    unordered_map<int,int> m;
    int n=arr.size();
    for(auto i:arr)
    m[i]++;
    // compress problem to k largest elememt
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int i=0;
    for(auto it:m)
    {
        if(i<k)
        {
            pq.push({it.second,it.first});
            i++;
            continue;
        }
        if(it.second>pq.top().first)
        {
            pq.pop();
            pq.push({it.second,it.first});
        }
    }
    vector<int>ans;
    while(pq.size()>0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
int main() {
    int n,k,num;cin>>n>>k>>num;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int> v=k_frequnt_ele(arr,n,k);
    for(auto i:v)
    cout<<i<<" ";
 return 0;
}