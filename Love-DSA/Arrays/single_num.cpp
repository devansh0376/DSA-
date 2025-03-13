#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// single number 1
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
int singleNumber_1(vector<int> &nums)
{
    int n = nums.size();
    /*
    int x=nums[0];
    for(int i=1;i<n;i++)
    {
        x^=nums[i];
    }
    return x;
    */
    // using binary search
    sort(nums.begin(), nums.end());
    int l = 0, h = n - 1;
    int ans;
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1])
            ans = nums[m];

        if ((m % 2 == 1 && nums[m] == nums[m - 1]) || (m % 2 == 0 && nums[m] == nums[m + 1]))
            l = m + 1;
        else
            h = m - 1;
    }
    return ans;
}
//single numebr 2
/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
*/
int singleNumber_2(vector<int>& arr) 
{
    int n=arr.size();
    int ans=0;
    for(int i=0;i<31;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=(arr[j] & (1<<i)); //ith bit is set or not 
        }
        if(sum%3!=0)
        ans+=(1<<i);
       // ans=ans | 1<<i;
    }
    return ans;
}
// single number 3
/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
*/
vector<int> singleNumber_3(vector<int> &arr)
{
    int n = arr.size();
    int xr = 0;
    for (auto i : arr)
        xr ^= i;
    // here all element that appear twice become zero and a^b=xr . a and b appear once
    //  we want find a and b first we find a then b=xr^a
    // we first find first set in xr means at that bit a or b are 1 or 0
    int bit;
    for (int i = 0; i < 31; i++)
    {
        if (xr & (1 << i))
        {
            bit = i;
            break;
        }
    }
    int mask =(1 << bit); // 011 101 => xr=110 mask=010
    //now we xor all element whose ith bit is set with mask
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & arr[i])
        a = a ^ arr[i];
    }
    b = xr ^ a;
    return {a, b};
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        arr.push_back(c);
    }

    return 0;
}