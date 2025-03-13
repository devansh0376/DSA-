#include<bits/stdc++.h>
using namespace std;
//find xor of 1 to n
/*
Ex : n=8 : 1^2^3^4^5^6^7^8 o/p:8
observation :
 N   XOR
 1   1    | 1%4=1    if(n%4==0)xor=n;
 2   3    | 2%4=2    if(n%4==1)xor=1;
 3   0    | 3%4=3    if(n%4==2)xor=n+1;
 4   4    | 4%4=0    if(n%4==3)xor=0;
 5   1    | 5%4=1
 6   7    | 6%4=2
 7   0    | 7%4=3
 8   8    | 8%4=0 
*/
int findxor(int n)
{
    if(n%4==0)
    return n;
    else if(n%4==1)
    return 1;
    else if(n%4==2)
    return n+1;
    else if(n%4==3)
    return 0;
}
// find xor in given range
/*
ex : l=4,r=8 -> 4^5^6^7^8 -> 8
8 = 1^2^3^4^5^6^7^8
4 = 1^2^3^4
8^4= 5^6^7^8 <- this is we want.
so we do xor(1 to r) ^ xor(1 to l-1)
*/
int que(int l,int r)
{
    return findxor(r)^findxor(l-1);
}
int main() {
    cout<<findxor(8)<<endl;
    cout<<que(4,8);
 return 0;
}