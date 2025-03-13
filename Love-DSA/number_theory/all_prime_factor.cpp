#include <bits/stdc++.h>
using namespace std;

bool check_prime(int n)
{
        if (n <= 1) return false; // 1 and numbers below are not prime
        for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        return false; // If divisible, not prime
    }
    return true; // Otherwise, it is prime
}
vector<int>AllPrimeFactors(int n) 
{
    // Code here
    vector<int> ans;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(check_prime(i))
            ans.push_back(i);
            
            if( (n/i)!=i &&  check_prime(n/i))
            ans.push_back(n/i);
        }
    }
    // for(int i=2;i<=n;i++)
    // {
    //     if(n%i==0)
    //     {
    //         ans.push_back(i);
            
    //         while(n%i==0)
    //         n=n/i;
    //     }
    // }
    return ans;
}
int main() {
    int n;cin>>n;
    vector<int> v=AllPrimeFactors(n);
    for(auto i:v)cout<<i<<" ";
 return 0;
}