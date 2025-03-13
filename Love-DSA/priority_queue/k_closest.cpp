#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// k cloest number : we have to return k number that are cloest to x mean their distant with x is minimum
/*
ex : 5 6 7 8 9 , k=3,x=7 , o/p : 6 7 8
brute force is to minus x from first e element and then sort base on substaction and return k number
 5 6 7 8 9
 7 7 7 7 7
 ---------   7 6 8     > ans
 2 1 0 1 2 : 0 1 1 2 2

 we optimzize this with our previous concept of return k smallest element 
-we make pair of max heap : first represent the this substraction element and second is for index of elememt 
-we find k small element base on first element then we return element base on second which is index 
*/
vector<int> k_closest(int arr[],int n,int k,int num)
{
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<n;i++)
    {
        int x=abs(arr[i]-num);
        if(i<k)
        {
            pq.push({x,i});
            continue;
        }
        //bcoz we have to maintain small element in heap
        if(x<pq.top().first)
        {
            pq.pop();
            pq.push({x,i});
        }
    }
    vector<int> v;
    while(pq.size()>0)
    {
        auto it=pq.top();
        v.push_back(arr[it.second]);
        pq.pop();
    }
    sort(v.begin(),v.end());
    return v;
}
int main() {
    int n,k,num;cin>>n>>k>>num;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int> v=k_closest(arr,n,k,num);
    for(auto i:v)
    cout<<i<<" ";
 return 0;
}