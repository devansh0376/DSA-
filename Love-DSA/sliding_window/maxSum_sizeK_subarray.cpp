#include <bits/stdc++.h>
using namespace std;
// Longest Sub-Array with Sum K
//brute force
/*
int mx=0;
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        long long s=0;
        for(int k=i;k<=j;k++)
        {
            // cout<<arr[k]<<" ";
            s+=arr[k];
        }
        if(s==k)
        {
            mx=max(mx,j-i+1);
        }
    }
}
*/
// for only positive elemenet : two pointer approch
int main() 
{
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)
    cin>>i;
    int mx=0,i=0,j=0,sum=0;
    while(j<n)
    {
        //calculation
        sum+=arr[j];
        if(sum<k)
        j++;
        else if(sum==k)
        {
            //store ans
            mx=max(mx,j-i+1);
            j++;
        }
        else //sum>k
        {
            //remove calculation    
            while(sum>k)
            {
                sum-=arr[i];
                i++;
            }
            j++;
        }
    }
    cout<< mx;
}
//for postive + negative element
/*
A[] = {10, 5, 2, 7, 1, 9}
K = 15
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)
    cin>>i;
    map<long long,int>m;
    int s=0,mx=0;
    for(int i=0;i<n;i++)
    {
        s+=arr[i];
        if(s==k)
        mx=max(mx,i+1); 
        int rem=s-k;
        if(m.find(rem)!=m.end())
        {   
            int l=i-m[rem]; 
            mx=max(mx,l);
        }
        //edge case when : arr[]=[ 2,0,0,0,3] for this we have store sum only once in map.Insort if sum is already exist in map we should not update in map.(it's index)
        if(m.find(s)==m.end())// we check that the sum is not present before
        m[s]=i;
    }
    cout<<mx;
   
}*/