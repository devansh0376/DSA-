#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
two types of heap = max heap(top element is maximum), min heap(top element is minimum)
->how to identify ? two keyword : k is given and find something small ot largest 
-> k + small = max heap 
-> k + large = min heap
*/
//kth small element 
/*
ex : 7 10 4 3 20 15 , k=3 o/p: 7
here the brute force approch is sort the array and return arr[k-1] element but it takes 0(n*log(n)) we optimize this and solve in 0(n*log(k))
-here we use max heap fisrt we push k element in heap and after that if element smaller than top element then we pop element and push current element bcoz we want to maintain small element in heap 
*/
int kth_small(int arr[],int n,int k)
{
    priority_queue <int> pq; 

    for(int i=0;i<n;i++)
    {
        if(i<k)
        {
            pq.push(arr[i]);
            continue;
        }
        if(arr[i]<=pq.top())
        {
            //int x=pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
//kth greater element 
/*
ex : 7 10 4 3 20 15 , k=3 o/p: 10
here the brute force approch is sort the array and return arr[n-k] element but it takes 0(n*log(n)) we optimize this and solve in 0(n*log(k))
-here we use min heap fisrt we push k element in heap and after that if element greater than top element then we pop element and push current element bcoz we want to maintain greater element in heap 
*/
int kth_large(int arr[],int n,int k)
{
    priority_queue <int,vector<int>,greater<int>> pq; 

    for(int i=0;i<n;i++)
    {
        if(i<k)
        {
            pq.push(arr[i]);
            continue;
        }
        if(arr[i]>pq.top())
        {
            //int x=pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main() 
{
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    cout<<"Kth large element :"<<kth_large(arr,n,k)<<endl;
    cout<<"Kth small element :"<<kth_small(arr,n,k)<<endl;
 return 0;
}