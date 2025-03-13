#include <bits/stdc++.h>
using namespace std;
/*
Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
intervals.
*/
// brute force : we sort the array and check next pair's start is less than previous pair's end (it's means this two tuppel is overlapping ) so we need to mearge them. end=max(end,next pair's end). if not overlapping we skip the pair.TC=0(N*longN)+0(2*N)
vector<vector<int>> solve1(vector<vector<int>> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0], end = arr[i][1];
        
        if (ans.size() > 0 && end <= ans.back()[1]) // avoding overlaping interaval(2,6) is already there kai rite khabar padse ? teni mate aa condtion
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
            else
                break;
        }
        ans.push_back({start, end});
    }
    return ans;
}
// optimal approch : we travers in singal loop 
vector<vector<int>> solve2(vector<vector<int>> arr)
{
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || arr[i][0]>ans.back()[1])
        ans.push_back(arr[i]);
            else
        { 
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    } 
    return ans;
}
int main()
{
    vector<vector<int>> arr;
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            int x, y;
            cin >> x >> y;
            arr.push_back({x, y});
        }
    }
    vector<vector<int>> ans = solve2(arr);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}