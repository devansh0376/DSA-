#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
you can buy and sell only once 
*/
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    //track of minimum element and maximize evry time diffence of curr and min element 
    int mn=arr[0];
    int profit=0;
    for(int i=1;i<n;i++)
    {
        int cost=arr[i]-mn;
        profit=max(profit,cost);
        mn=min(mn,arr[i]);
    }
    cout<<profit;
 return 0;
}