#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    int data;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
class stack
{
public:
    node *top = NULL;
    void push(int x)
    {
        node *new_node = new node(x);
        new_node->next = top;
        top = new_node;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            node *ptr = top;
            top = top->next;
            free(ptr);
        }
    }
    int top_ele()
    {
        if (top == NULL)
            return 0;
        else
            return top->data;
    }
    bool isempty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
};
int main()
{
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.top_ele() << endl;
    s1.pop();
    s1.pop();
    cout<<s1.top_ele();
    return 0;
}