#include <bits/stdc++.h>
using namespace std;
/*
You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.
Input: [3, 8, 5, 7, 6]
Output: 4
Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
*/
int longestConsecutive(int arr[], int n)
{
    // brute force
    /*
    int mx=0;
    for(int i=0;i<n;i++)
    {
        int k=arr[i];
        int c=0;
        while(ls(arr,k))
        {
            k++;
            c++;
        }
        mx=max(mx,c);
    }
    return mx;
    */
    // better solution
    /*if(n==0)return 0;
    sort(arr.begin(),arr.end());
    int lastsmaller=INT_MIN;
    int longest=0;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]-1==lastsmaller)
        {
            c++;
            lastsmaller=arr[i];
        }
        else if(arr[i]!=lastsmaller)
        {
            c=0;
            lastsmaller=arr[i];
        }

        longest=max(longest,c);
    }
    return longest+1;*/
    // optimal soltion
    if (n == 0)
        return 0;
    unordered_set<int> st;
    for (auto i : arr)
        st.insert(i);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        // mean it is starting point
        // if it true so it mean it not the star point of consecutive element
        if (!st.count(arr[i] - 1))
        {
            int x = arr[i];
            int c = 0;
            while (st.count(x + 1))
            {
                x++;
                c++;
            }
            mx = max(mx, c);
        }
    }
    return mx + 1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    int ans = longestConsecutive(arr, n);
    cout << ans;
    return 0;
}