#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
//find all prime number between 1 to n
//brute force for(1 to n)check the prime number ans add in to ans
/*
The sieve of Eratosthenes is one of the most efficient ways to find all primes from 1 to n
->in this we make one prime array inthat we store all prime number this is kind of boolen array if there is 1 then ith 
number is prime else non-prime;
->for make this array we traverse from 1 to n and chek if ith number is marked or not 
if marked so it is prime number now we unmark all it's factor this proceess continue till n and we got our array 
*/
int n;
vector<int> v;
void siev()
{
    for(int i=2;i*i<=n;i++)
    {
        if(v[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)
            v[j]=0;
        }
    }
}
vector<int> sieveOfEratosthenes(int x)
{
    // Write Your Code here
    n=x;
    v.assign(n + 1, 1);
    v[0]=v[1]=0;
    siev();
    vector<int> ans;
    for(int i=1;i<=x;i++)
    {
        if(v[i]==1)
        ans.push_back(i);
    }
    return ans;
}
/*
Time Complexity: O(N*log(log(N)))
Auxiliary Space: O(N)
*/
int main() {
    int x;
    cin>>x;
    vector<int> ans=sieveOfEratosthenes(x);
    for(auto i:ans)
    cout<<i<<" ";
 return 0;
}