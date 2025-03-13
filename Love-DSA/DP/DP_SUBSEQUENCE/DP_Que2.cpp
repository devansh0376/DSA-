#include<bits/stdc++.h>
using namespace std;
//subset sum problems
//find that there exist a subset or not,whose sum is k
/*
i/p:2 3 7 8 10,k=11 o/p:yes
->here one array is given and one sum/W is given and we have to chose multiple option,knapsack pattertn
->here one array is given so we consider this array as a weight array.
->base case: if sum is zero return true. if n==0 return false
*/
/*
1> Equal sum partion
->find that the given array can be partion in two part. whose sum is euqal.
->simple calucalte the array sum and call below funtion for sum/2.
2> count of subset sum whose sum is k
->whenever there are how many ways,count way so sum all funtion call.
*/
bool solve1(int arr[],int n,int sum)
{
    if(sum==0)
    return true;
    if(n==0)
    return false;
    if(arr[n-1]<=sum)
    return ( solve1(arr,n-1,sum-arr[n-1]) || solve1(arr,n-1,sum) );
    else
    return solve1(arr,n-1,sum);
}
bool solve2(int arr[],int n,int sum,vector<vector<int>>v)
{
    if(sum==0)
    return true;
    if(n==0)
    return false;
    if(v[n][sum]!=-1)
    return v[n][sum];
    if(arr[n-1]<=sum)
    return v[n][sum]=( solve1(arr,n-1,sum-arr[n-1]) || solve1(arr,n-1,sum) );
    else
    return v[n][sum]=solve1(arr,n-1,sum);
}
bool solve3(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            dp[i][j]=0;
            if(j==0)
            dp[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=(dp[i-1][j-arr[i-1]]|| dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main() {
    int n,sum;cin>>n>>sum;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans1=solve1(arr,n,sum);
    cout<<ans1<<endl;
    vector<vector<int>>v(n+1,vector<int>(sum+1,-1));
    int ans2=solve2(arr,n,sum,v);
    cout<<ans2<<endl;
    int ans3=solve3(arr,n,sum);
    cout<<ans3<<endl;
 return 0;
}