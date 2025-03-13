#include <bits/stdc++.h>
using namespace std;
/*
->Dutch National Flag algorithm : The algorithm works by maintaining three pointers: low, mid, and high. The low pointer points to the beginning of the array, the high pointer points to the end of the array, and the mid pointer starts at the beginning of the array and moves through it.
*/
/*The idea behind the algorithm is to keep all the 0s before the low pointer, all the 2s after the high pointer, and all the 1s between the low and high pointers.*/
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &i : arr)
    cin >> i;
    int l = 0, m = 0, h = n - 1;
    while (m <= h)
    {
        if (arr[m] == 0)
        {
            swap(arr[l], arr[m]);
            l++;
            m++;
        }
        else if (arr[m] == 1)
            m++;
        else if (arr[m] == 2)
        {
            swap(arr[m], arr[h]);
            h--;
        }
    }
    for(auto i:arr)cout<<i<<" ";
    return 0;
}