#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if(n==1)return 0;
    if(n==2)return 1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
//iterate from 1 to n. pick one i and mark all it's divisible number as 0. at last all number are mark as 1 is prime numebr 
void sive(int n)
{
    vector<int> v(n+1,1);
    for(int i=2;i*i<=n;i++)
    {
        if(v[i])
        {
            for(int j=i*i;j<=n;j+=i)
            v[j]=0; 
        }
    }
    v[0]=0;
    v[1]=0;
    for(int i=0;i<=n;i++)
    {
        if(v[i])
        cout<<i<<" ";
    }
}
int main() {
    //cout<<is_prime(4);
    sive(20);
}