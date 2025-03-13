#include<bits/stdc++.h>
using namespace std;
//spilt array largest sum
/*
->Given an positive integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. 
i/p: 7,2,5,10,8 k=2 o/p:18
->there is a four way to creat subarray. 7|2,5,10,8 ->maxsum=25 7,2|5,10,8 ->maxsum=23, 7,2,5|10,18 ->maxsum=18
  7,2,5,10|18 ->maxsum=24 
->minimum maxsum is 18. for get minimumm sum we have to distribuite equal sum to every subarray
-> search space is 0 t  o array sum. if partion is possible move left(bcoz we want to minimize the sum) and if not move rigth
*/
bool ispossible(int arr[],int n,int max_sum,int k)
{
    int subarray_sum=0,subarray_cnt=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_sum)return false;
        subarray_sum+=arr[i];
        if(subarray_sum>=max_sum)//we got our first partition
        {
            subarray_cnt++;
            subarray_sum=arr[i];
        }
        if(subarray_cnt>k)
        return false;
    }
    return true;
}
int spiltarray(int arr[],int n,int k)
{
    int l=*max_element(arr,arr+n),h=accumulate(arr,arr+n,0),mid=(h+l)/2;
    while(l<=h)
    {
        if(ispossible(arr,n,mid,k))
        h=mid-1;
        else
        l=mid+1;
        mid=(l+h)/2;
    }
    return l;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans=spiltarray(arr,n,k);
    cout<<ans;
 return 0;
}