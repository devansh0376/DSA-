#include<bits/stdc++.h>
using namespace std;
// Detect the loop in LL
/*
subproblems : 
->detect the loop , return stating node of loop , length of loop , delete loop
*/
class node
{
    public:
    node *next;
    int data;
    node(int k)
    {
        next=NULL;
        data=k;
    }
};
class SLL
{
    public:
    node *head;
    SLL(){ head=NULL; }
    void insert(node *&head,int k)
    {
        node *new_node=new node(k);
        if(head==NULL)
        {
            new_node->next=head;
            head=new_node;
        }
        else
        {
            node *ptr=head;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=new_node;
        }
    }
    void display(node *&head)
    {
        node *ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        cout<<"NULL";
    }
    bool detectloop(node *&head)
    {
        node *ptr=head;
        map<node*,bool>visited;
        while(ptr!=NULL)
        {
            if(visited[ptr]==true)
            return true;
            visited[ptr]=true;
            ptr=ptr->next;
        }
        return false;
    }
    node *first_node(node *&head)
    {
        node *ptr=head;
        map<node*,bool>visited;
        while(ptr!=NULL)
        {
            if(visited[ptr]==true)
            return ptr;
            visited[ptr]=true;
            ptr=ptr->next;
        }
        return NULL;
    }
    int length_loop(node *&head)
    {
        node *ptr=first_node(head);
        node *temp=ptr;
        int length=0;
        if(ptr==NULL)return 0;
        while(temp->next!=ptr)
        {
            temp=temp->next;
            length++;
        }
        return length+1;
    }
    void delete_loop(node *&head)
    {
        if(head==NULL)return;
        node *ptr=first_node(head);
        node *temp=ptr;
        while(temp->next!=ptr)
        temp=temp->next;
        temp->next=NULL;
    }
};
int main() {
    node *head=NULL;
    SLL s1;
    s1.insert(head,1);
    s1.insert(head,2);
    s1.insert(head,3);
    s1.insert(head,4);
    s1.display(head);
 return 0;
}