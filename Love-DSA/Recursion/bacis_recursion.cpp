#include<bits/stdc++.h>
using namespace std;
long long M=1e9+7;
/*
->recursion : funtion call it self
-> how to identify recurion problem
  - choise + decision (many choise and decision may include or not include)
-> how to solve recursion problem
  -make a problem in formula type 
  -make a desion we take this or not
  -make base condition(when recursion stops)
->how to make base condition
  -make small valid input
  -or make input invalid
*/
/*
5!=5*4*3*2*1 , 4!=4*3*2*1 ,3!=3*2*1 
5!=5*4!
n!=n*(n-1)!
*/ 
int fact(int n)
{
    if(n==0)
    return 1;
    return n*fact(n-1);
}
/*
0 1 1 2 3 5 8 13
5th fib no.= (3th fib no. + 2th fib no.)
nth fib no.=(n-1)th fib no. + (n-2)th fib no.
smallest valid i/p : 0 1 ; 0->0,1->1
nth fib no= fib(n-1)+fib(n-2)
*/
int fib(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    return fib(n-1)+fib(n-2);
}
/*
power of 2 : 
2^4= 2*2*2*2, 2^3=2*2*2 
2^4= 2*2^3
2^n=2*(2^n-1)
formula : 2*power(n-1); base condition : 2^0=1
*/
int power(int n)
{
  if(n==0)
  return 1;
  if(n==1)
  return 2;
  return  2*power(n-1);
}
long long power(int a,int b)
{
 //Your code here
  if(b==0)
  return 1;
  long long x=power(a,b/2)%M;
  long long ans=(x*x)%M;
  if(b%2==1)
  {
    ans=a*ans;
  }
  return ans%M;
  }
/*
digit sum
->1234 op:10 4+3+2+1
->(n%10+(n/10)%10+.....) : every time we add n%10 and divide n/10 
-> n=0 -)0
*/
int digitsum(int n)
{
  if(n==0)return 0;
  return (n%10+digitsum(n/10));
}
void fun(int n,int i)
{
    if(i>n)
    return ;
    fun(n,i+1);
    cout<<i<<endl;
}
void fun1(int n)
{
    if(n==0)
    return;
    cout<<"pre "<<n<<endl;
    fun1(n-1);
    cout<<"In "<<n<<endl;
    fun1(n-1);
    cout<<"post "<<n<<endl;
}
//sum of n natual number
int fun3(int n)
{
    if(n==0)
    return 0;
    return n+fun3(n-1);
}
//array reverse
void fun4(int arr[],int i,int j)
{
    if(i>j)
    return;
    swap(arr[i],arr[j]);
    fun4(arr,i+1,j-1);
}
//string is palimdrom or not
bool fun5(string s,int n,int i)
{
     if(i>=n/2)
     return true;
     if(s[i]!=s[n-i-1])
     return false;
     return fun5(s,n,i+1);
}

int main() {
    int n;cin>>n;
    //for nth fibonaci number
    cout<<endl;
    //cout<<fib(n)<<endl;
    //cout<<power(n);
    //cout<<digitsum(n);
    cout<<fun3(n);
 return 0;
}