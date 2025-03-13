#include<bits/stdc++.h>
using namespace std;
/*
Q1> Binary subarray with sum
Given a binary array arr of size N and an integer target, return the number of non-empty subarrays with a sum equal to target
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1],[1,0,1,0,1],[1,0,1,0,1],[1,0,1,0,1]
*/
/*
Q2>Count Subarray with k odds
You are given array nums of n elements and integer K, and count the number of subarrays that has k odd numbers
Input: n = 5,nums = [1,1,2,1,1],k = 3
Output: 2
Explanation: There are 2 subarrays with k odds [1,1,2,1] and [1,2,1,1]
*/
/*
q3>Subarrays with K Different Integers
Given an integer array nums and an integer k, return the number of good subarrays of nums.A good array is an array where the number of different integers in that array is exactly k.
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
*/
// here we do slide modification.for this type of proble when window size is not given and they don't ask for mx length of window. we shoudl do slide modification, as below
/*
-> how to identify : no window size given and not aks for maxmize the window
-> how to solve:
format: 
while(j<n)
{
    //calculation
    while(cond>k)
    {   
        //remove calculation
        i++;
    }
    //store ans
    j++;
}
x+y<z -> y<z :-> here if 0 1 0 < 3 so 0 1,1 0,0,1 all subarray is less than 3.so there for we add full lenght of window(Subaray).
and we call this function two time one for k and other for k-1.
k 2 : 0 1 2 | k 2 - k 1
k 1 : 0 1   | 0 1 2 - 0 1 = 2 and we want calculation for 2
*/
int atmost(int n, vector<int> &arr, int k)
{
    int i = 0, j = 0, mx = 0, c = 0;
    while (j < n)
    {
        if (arr[j] % 2)
        c++;
        while (c > k)
        {
            if (arr[i] % 2)
                c--;
            i++;
        }
        mx += (j - i + 1); // x+y<z -> y<z :-> here if 0 1 0 < 3 so 0 1,1 0,0,1 all subarray is less than 3.so there for we add full lenght of window(Subaray)
        j++;
    }
    return mx;
}
int main() {
    int n,k;cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        arr.push_back(x);
    }
    cout<<atmost(n,arr,k)-atmost(n,arr,k-1);
 return 0;
}