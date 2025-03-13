#include <bits/stdc++.h>
using namespace std;
/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
N = 3,Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
*/
// aproch 1:using hash map TC: 0(N) and SC=0(N)
vector<int> solve1(int arr[], int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    int r = -1, m = -1;
    for (int i = 1; i <= n + 1; i++)
    {
        if (hash[i] == 2)
            r = i;
        else if (hash[i] == 0)
            m = i;
        if (r != -1 && m != -1)
            break;
    }
    return {r, m};
}
// usign maths in 0(1)
/*
here we have two unknown element. so for this we need two equestion.assume that number is alphabet.
arr[]=[a,e,c,d,e] ->orignal array[]=[a,b,c,d,e]-> ans : e is reapiting and b missing
sumof(1 to n)-sum(arr)=a+b+c+d+e-(a+e+c+d+e)=x -> b-e=x --->eq(1)
sumof squre sum(1 to n)-sum of squre sum(arr)= a^2+b^2+c^2+d^2+e^2-(a^2+e^2+c^2+d^2+e^2)=y =>b^2-e^2=y --->eq(2)
eq(2)/eq(1) = b^2-e^2/b-e = y/x -> (b+e)*(b-e)/(b-e) = y/x => b+e=y/x --->eq(3)
from eq(1) and eq(3) we can find b and e where b is missing and e is reapting number
b+e = y/x | b=c;  -> e=x-b=x-c
b-e = x   | e=d; 
*/
vector<int> solve2(int arr[], int n)
{
    long long sn = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }
    long long eq1=sn-s; //b-e=x --->eq(1)
    long long eq2=s2n-s2; //b^2-e^2=y --->eq(2)
    long long eq3=eq2/eq1;//b+e=y/x --->eq(3)
    int missing = (eq1+eq3)/2 ;// (b+e)+(b-e) = ((y/x)+x )-> b=((y/x)+x )/2
    int repeting=(eq3-missing);

    return {{repeting,missing}};
}
//approch 3:using swap sort
/*      index(i) 0 1 2 3 4  :>for if index =i so element is i+1 
->ideal array = [1,2,3,4,5] 
->if array element is i so it's index must be at i-1.if that element is not present in this index we place that.
ex :0 1 2 3 4 | 0 1 2 3 4 |now at index:3 conditon is not match(arr[i]!=i+1) so this is our missing and repeting
    2 3 1 5 1 | 1 2 3 1 5 | missing=i+1 and repeting=arr[i]
->for this callde swap sort algo
->if(i!=arr[i-1]) swap(arr[i-1],arr[i]) whenever this condition false we increment our i
->whenever we reach at repeting missing number.so we will stuck in loop.so we swap if(arr[i]!=arr[i]-1) if this is not true means this is our dublicate element.
-> simple algorithm: 
for every i check that if arr[i]==arr[i]-1(mean it is at it's right position) so do i++ else do swap
*/
vector<int> solve3(int arr[],int n)
{
    int i=0;
    while(i<n)
    {
        int x=arr[i];
        if(i==x-1)
        i++;
        else
        {
            if(x!=arr[x-1])
            swap(x,arr[x-1]);
        }
    }
    int repeting=-1,missing=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=i+1)
        {
            missing=i+1;
            repeting=arr[i];
            break;
        }
    }
    return {{repeting,missing}};
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int>v1=solve1(arr,n);
    vector<int>v2=solve2(arr,n);
    vector<int>v3=solve3(arr,n);
    cout<<v1[0] <<" "<< v1[1]<<endl;
    cout<<v2[0] <<" "<< v2[1]<<endl;
    cout<<v3[0] <<" "<< v3[1]<<endl;
    return 0;
}