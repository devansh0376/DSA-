#include<bits/stdc++.h>
using namespace std;
//Kth Missing Positive Number
/*
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/
int ans1(int arr[],int n,int k)
{
    int i=0,j=1;
    while(k)
    {
        if(i<n && arr[i]==j)
        i++,j++;
        else
        j++,k--;
    }
    return j-1;
}
/* 0 1 2 3 4   | 0 1 2 3 4 5 | x=arr[mid]-mid ; :> x denotes number of missing element
->[2,3,4,7,11] | l         h | 
*/
int ans2(int arr[],int n,int k)
{
    int l=0,h=n;
    while(l<=h)
    {
        int mid=(l+h)/2;
        int x=arr[mid]-mid; // x denotes the number of missing element
        if(x<k)
        l=mid+1;
        else
        h=mid-1;
    }
    return l+k;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    cout<<ans1(arr,n,k)<<endl;
    cout<<ans2(arr,n,k)<<endl;
 return 0;
}