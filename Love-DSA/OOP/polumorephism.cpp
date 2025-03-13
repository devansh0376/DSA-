#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
    void fun()
    { cout<<"Say hii"; }
    void fun(int a)
    { cout<<"Say hii"; } 
    void operator () ()  
    { cout<<"hello"; }
};
int main() {
    A obj;
    obj();
 return 0;
}