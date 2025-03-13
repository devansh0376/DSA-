#include <iostream>
using namespace std;
#define n 100
class stack
{
    public :
    int arr[n];
    int top;
    stack()
    {
        top=-1;
    }
    void push(int x)
    {
        if(top==n-1)
        cout<<"Stack overflow"<<endl;
        else
        arr[++top]=x;
    }
    void pop()
    {
        if(top==-1)
        cout<<"Stack is empty"<<endl;
        top--;
    }
    int top_ele()
    {
        if(top==-1)
        {
            //cout<<"Stack is empty"<<endl;
            return 0;
        }
        else
        return arr[top];
    }
    bool isempty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }
};
int main() {
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.top_ele()<<endl;
    s1.pop();
    s1.pop();
    cout<<s1.top_ele();
 return 0;
}