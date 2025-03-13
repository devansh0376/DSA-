#include <bits/stdc++.h>
using namespace std;
/*
->Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
Input :
N = 8,K = 3
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
Output :-1 -1 -7 -15 -15 0
*/
#define ll long long
vector<int> ans1(int arr[], int n, int k)
{
    vector<int> v;
    for (int i = 0; i < n - k + 1; i++)
    {
        int t = 1;
        for (int j = i; j < i + k; j++)
        {
            if (arr[j] < 0)
            {
                t = 0;
                v.push_back(arr[j]);
                break;
            }
        }
        if (t)
            v.push_back(0);
    }
    return v;
}
// using sliding window
/*
ex: arr[] :12 -1 -7 8 -15 30 16 28
dq : [1 2 4 ] . ans: [-1 -1 -7 -15 -15 0]
*/
vector<int> ans2(int arr[], int n, int k)
{
    int i = 0, j = 0;
    deque<int> dq;
    vector<int> v;
    while (j < n)
    {
        if (dq.size() > 0 && dq.front() == j - k)
            dq.pop_front();

        if (arr[j] < 0)
            dq.push_back(j);

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (dq.size() > 0)
                v.push_back(arr[dq.front()]);
            else
                v.push_back(0);
            i++;
            j++;
        }
    }
    return v;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    vector<int> v1 = ans1(arr, n, k);
    vector<int> v2 = ans2(arr, n, k);
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    for (auto i : v2)
        cout << i << " ";
    cout << endl;
    return 0;
}