#include<bits/stdc++.h>
using namespace std;
// Maximum Points You Can Obtain from Cards
/*
->there are number of cards.and you have to select excatly k cards. you can pick it from begining or end.
if you pick m cards from begining you must pick k-m cards from end 
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
*/
//approch
/*
here we want to maximize k element sum.
    /*
    [1,2,3,4,5,6,1] , sum           | we minimize the window of n-k size
    1          6 1     8            | 2 3 4 5 -> 14
    1 2          1     4            | 3 4 5 6 -> 15
    1 2 3              6            | 4 5 6 1 -> 16
             5 6 1     12 -> ans=12 | 1 2 3 4 -> 10(min) sum-10> 22-10=12(ans)
*/
int maxScore(int arr[],int n, int k) {
    int w_sum=0,all_sum=0;
    int rem=n-k;
    for(int i=0;i<rem;i++)
    {
        w_sum+=arr[i];
        all_sum+=arr[i];
    }
    int mn=w_sum;
    for(int i=rem;i<n;i++)
    {
        all_sum+=arr[i];
        w_sum+=arr[i];
        w_sum-=arr[i-rem];
        mn=min(mn,w_sum);
    }
    int ans=all_sum-mn;
    return ans;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)
    cin>>i;
    cout<<maxScore(arr,n,k);
 return 0;
}