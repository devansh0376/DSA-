#include <bits/stdc++.h>
using namespace std;
/*
Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.
Input Format: N = 5, array[] = {1,2,2,3,2}
Result: 2
Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.
*/
vector<int> ans(int arr[], int n)
{
    vector<int> v;
    int me1, me2, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (c1 == 0 && me2 != arr[i])
        {
            c1 = 1;
            me1 = arr[i];
        }
        else if (c2 == 0 && me1 != arr[i])
        {
            c2 = 1;
            me2 = arr[i];
        }
        else if (me1 == arr[i])
            c1++;
        else if (me2 == arr[i])
            c2++;
        else
        {
            c1--;
            c2--;
        }
    }
    int ct1 = 0, ct2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == me1)
            ct1++;
        if (arr[i] == me2)
            ct2++;
    }
    if (ct1 > (n / 3))
        v.push_back(me1);
    if (ct2 > (n / 3))
        v.push_back(me2);

    if (v.size() == 0)
        v.push_back(-1);
    return v;
}
//same algorithm for majority element who repets more than n/4  time
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int c1=0,c2=0,c3=0,me1,me2,me3;
    for(int i=0;i<n;i++)
    {
        if(c1==0 && me2!=arr[i] && me3!=arr[i])
        c1=1,me1=arr[i];
        else if(c2==0 && me1!=arr[i] && me3!=arr[i])
        c2=1,me2=arr[i];
        else if(c3==0 && me1!=arr[i] && me2!=arr[i])
        c3=1,me3=arr[i];
        else if(me1==arr[i])
        c1++;
        else if(me2==arr[i])
        c2++;
        else if(me3==arr[i])
        c3++;
        else
        {
            c1--;c2--;c3--;
        }
    }
    int ct1=0,ct2=0,ct3=0;
    for(int i=0;i<n;i++)
    {
        if(me1==arr[i])ct1++;
        if(me2==arr[i])ct2++;
        if(me3==arr[i])ct3++;
    }
    if(ct1>(n/4))cout<<me1<<endl;
    if(ct2>(n/4))cout<<me2<<endl;
    if(ct3>(n/4))cout<<me3<<endl;
}
*/
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> i;
    vector<int>v= ans(arr, n);
    for(auto i:v)cout<<i<<" ";
    return 0;
}