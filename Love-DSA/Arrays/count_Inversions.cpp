#include <bits/stdc++.h>
using namespace std;
/*
Given an array of N integers, count the inversion of the array (using merge-sort).
What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Input Format: N = 5, array[] = {5,4,3,2,1}
Result: 10
Explanation: we have a reverse sorted array and we will 
get the maximum inversions as for i < j we will always 
find a pair such that A[j] < A[i]. 
Example: 5 has index 0 and 3 has index 2 now (5,3) pair 
is inversion as 0 < 2 and 5 > 3 which will satisfy out 
conditions and for reverse sorted array we will get 
maximum inversions and that is (n)*(n-1) / 2.

For above given array there is 4 + 3 + 2 + 1 = 10 inversions.
*/
int merge(long long arr[], int low, int mid, long long high)
{
    // Your code here
    int c = 0;
    vector<int> temp;
    long long left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        // left is small
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        // right is small
        else
        {
            temp.push_back(arr[right++]);
            c += (mid - left + 1);
        }   
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return c;
}
long long mergeSort(long long arr[], int low, long long high)
{
    // code here
    long long c = 0;
    if (low >= high)
        return c;
    int mid = (low + high) / 2;
    c += mergeSort(arr, low, mid);
    c += mergeSort(arr, mid + 1, high);
    c += merge(arr, low, mid, high);
    return c;
}
long long int inversionCount(long long arr[], long long n)
{
    // Your Code Here
    return mergeSort(arr, 0, n - 1);
}
int main()
{
    long long n;cin>>n;
    long long arr[n];
    for(auto &i:arr)cin>>i;
    long long ans=inversionCount(arr,n);
    cout<<ans;
    return 0;
}