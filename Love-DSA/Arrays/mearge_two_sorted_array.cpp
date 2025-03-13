#include <bits/stdc++.h>
using namespace std;
/*
 Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
 Input: 
n = 4, arr1[] = [1 4 8 10] 
m = 3, arr2[] = [2 3 9]
Output: 
arr1[] = [1 2 3 4]
arr2[] = [8 9 10]
 */
void merge(int a[],int b[], int n, int m)
{
    // code here
    /* vector<int>v;
     for(int i=0;i<n;i++)
     {
         v.push_back(a[i]);
     }
     for(int i=0;i<m;i++)
     {
         v.push_back(b[i]);
     }
     sort(v.begin(),v.end());
     for(int i=0;i<v.size();i++)
     {
         if(i<n)
         a[i]=v[i];
         else
         b[i-n]=v[i];
     }
     */
    /*
    vector<int>v;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        v.push_back(a[i++]);
        else if(b[j]<a[i]) 
        v.push_back(b[j++]);
        else
        {
            v.push_back(a[i]);
             v.push_back(b[j]);
            i++;j++;
        }
    }
    while(i<n)v.push_back(a[i++]);
    while(j<m)v.push_back(b[j++]);
    for(int i=0;i<v.size();i++)
    {
        if(i<n)
        a[i]=v[i];
        else
        b[i-n]=v[i];
    }
    */
    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(a, a + n);
    sort(b, b + m);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    merge(a, b, n, m);
    for(auto i:a)cout<<i<<" ";cout<<endl;
    for(auto i:b)cout<<i<<" ";cout<<endl;
    return 0;
}