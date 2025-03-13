#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*We are asked to find the number of subarrays thats sum are divisible by N 
EX : n=5 , arr= 1 4 2 7 3
o/p : 2
subarray that divisible by n : {1,4},{7,3}
b-a%N==0 => b%N= a%N
subarray_sum(i,j)=subarray_sum(0,j)-subarray_sum(0,i-1)
  1 4 2 7 3
0 1 5 7 14 17 } prefix sum array
0 1 0 2  4  2 }sum%n
0->2  } -> presum
1->1
2->2
4->1 
->have ahiya 2 sum chose karva na 6 > b and a jethi b-a%N==0 thay tenu formula Nc2 = n*(n-1)/2
*/
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    ll sum=0;
    int presum[n]={0};
    presum[0]=1;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        sum%=n;
        sum=(sum+n)%n;
        presum[sum]++;
    }
    long long ans=0;
    for(auto i:presum)
    {
        ans+=i*(i-1)/2;
    }
    cout<<ans<<endl;
     return 0;
}