#include<bits/stdc++.h>
using namespace std;
/*
-> Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
Input: arr = [4,0,-1,3,5,3,6,8], k = 3
Output: [4,3,5,5,6,8]
Explanation: 

Window position                   Max
------------------------         -----
[4  0  -1] 3  5  3  6  8           4
 4 [0  -1  3] 5  3  6  8           3
 4  0 [-1  3  5] 3  6  8           5
 4  0  -1 [3  5  3] 6  8           5
 4  0  -1  3 [5  3  6] 8           6
 4  0  -1  3  5 [3  6  8]          8

For each window of size k=3, we find the maximum element in the window and add it to our output array.
*/
//approch 1 : iteret through all subarray and calculate maximum for k size subarray.TC=0(n*n)
vector<int> ans1(int arr[],int n,int k)
{
    vector<int>v;
    for(int i=0;i<n-k+1;i++) //output size is n-k+1
    {
        int mx=INT_MIN;
        for(int j=i;j<i+k;j++)//for move size k window 
        {
            mx=max(mx,arr[j]);
        }
        v.push_back(mx);
    }
    return v;
}
// approch 2 : using deque //TC=0(N)
/*
->here we store index in deque.and when we get our k size subarray we push element in our ans.we store in decresing ordered in deque
->if(arr[i]>=dq.front) : we pop element from back.else we push element in deque
->if out deque store more than k element we pop element from front.
->we store index in deque
*/
vector<int> ans2(int arr[],int n,int k)
{
    vector<int>v;
    deque<int>dq;
    for(int i=0;i<n;i++)
    {
        //for remove out bound index..and for maintain size of deque k
        if(dq.size()>0 && dq.front()==i-k)
        dq.pop_front();
        //for maintain decresing oredered in deque.
        while(dq.size()>0 && arr[i]>=arr[dq.back()])
        dq.pop_back();

        dq.push_back(i);
        if(i>=k-1)
        v.push_back(arr[dq.front()]);
    }
    return v;
}
//approch 3: using two pointer. 
vector<int> ans3(int arr[],int n,int k)
{
    vector<int>v;
    int i=0,j=0;
    deque<int>dq;
    int mx=INT_MIN;
    if(k>n)
    {
        v.push_back(*max_element(arr,arr+n));
        return v;
    }
    while(j<n)
    {
        while(dq.size()>0 && arr[j]>dq.back())
        dq.pop_back();
        dq.push_back(arr[j]);
        if(j-i+1<k)
        j++;
        else if(j-i+1==k) // we got window of size k
        {
            v.push_back(dq.front());
            if(arr[i]==dq.front())
            dq.pop_front();
            i++;j++;//move window of size k
        }
    }
    return v;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int>v1=ans1(arr,n,k);
    vector<int>v2=ans2(arr,n,k);
    vector<int>v3=ans3(arr,n,k);
    for(auto i:v1)cout<<i<<" ";cout<<endl;
    for(auto i:v2)cout<<i<<" ";cout<<endl;
    for(auto i:v3)cout<<i<<" ";cout<<endl;
 return 0;
}