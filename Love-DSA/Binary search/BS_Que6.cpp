#include<bits/stdc++.h>
using namespace std;
// find a floor and ceil of an element in sorted array(Impliment lower bound)
int floor(int arr[],int n,int k)
{
    int  l=0,h=n-1,mid=(l+h)/2,ans=-1;
    while(l<=h)
    {
        if(arr[mid]==k)
        return mid;
        else if(k>arr[mid])
        {
            ans=mid;
            l=mid+1;
        }
        else
        h=mid-1;
        mid=(l+h)/2;
    }
        
    return ans;
}
int ceil(int arr[],int n,int k)
{
    int l=0,h=n-1,mid=(l+h)/2,ans=-1;
    while(l<=h)
    {
        if(arr[mid]==k)
        return mid;
        else if(k>arr[mid])
        l=mid+1;
        else
        {
            ans=mid;
            h=mid-1;
        }
        mid=(l+h)/2;
    }
    return ans;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)
    cin>>i;
    cout<<"Floor of the element :"<<floor(arr,n,k)<<endl;
    cout<<"ceil of the element :"<<ceil(arr,n,k)<<endl;
 return 0;
}