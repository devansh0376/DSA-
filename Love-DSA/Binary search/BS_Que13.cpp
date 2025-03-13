#include<bits/stdc++.h>
using namespace std;
// coko eats banana
/*
->n piles of banana.ith pile hase a[i] banana. you are given H hour to eat this all banana. find the minimum number of bananas each per hour so coko can eat all this banana in H hour.
i/p: 3 6 7 11,h=8 } 3 6 7 11
o/p: 4            } 1 2 2 3 -)1+2+2+3=8 so we can can eat all banana in H hour. so minimum banana to eat per hour is 4.
*/
bool ispossible(int arr[],int n,int max_hour,int max_banana)
{
    int h=0;
    for(int i=0;i<n;i++)
    {
        h+=ceil(arr[i]*1.0/max_banana);
        if(h>max_hour)
        return false;
    }
    return true;
}
int min_banana(int arr[],int n,int max_hour)
{
    int l=0,h=*max_element(arr,arr+n),mid=(l+h)/2;
    while(l<=h)
    {
        if(ispossible(arr,n,max_hour,mid))
        h=mid-1;
        else
        l=mid+1;
        mid=(l+h)/2;
    }
    return l;
}
int main() {
    int n,h;cin>>n>>h;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans=min_banana(arr,n,h);
    cout<<ans;
 return 0;
}