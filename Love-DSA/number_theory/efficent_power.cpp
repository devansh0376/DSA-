#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// int main()
// {
    // int x,n;cin>>x>>n;
    // int ans = 1; //x^n
    // for (int i = 0; i < n; i++) {
    //     ans = ans * x;
    // }
    // cout <<x<<" raised to the power "<<n<<" is "<< ans;
//}

/*
To efficiently calculate the power of a number, especially when dealing with large exponents, we can use Binary Exponentiation. We reduce the number of multiplication operations needed to compute the power by breaking down the exponent to its half, smaller operations.

At each step of the loop, we check whether the current exponent is even or odd.

If the exponent is even, we square the base as xn = (x2)n/2.
If the exponent is odd, the algorithm multiples the result by the base as xn = x(xn-1).
*/

int solve(int x,int n) // x^n
{
    if(n==0)return 1;

    int temp=solve(x,n/2);

    if(n%2==0)
    return temp*temp;
    else
    return x*temp*temp;
}
//Time Complexity:O(log(N))where N is the exponent.
int solve1(int x,int n)
{
    int ans=1;
    int m=n;
    while(n>0)
    {
        if(n%2==1)
        {
            ans=ans*x;
            n--;
        }
        else
        {
            n=n/2;
            x=x*x;
        }
    }
    if(m<0)
    return 1/ans;
    return ans;
}
// 2^5 = 
int main() 
{
    int x,n;cin>>x>>n;
    // int ans =pow(x,n);
    int ans =solve1(x,n);

    cout <<x<<" raised to the power "<<n<<" is "<< ans;
}
                  