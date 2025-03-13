#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    node *next,*prev;
    int data;
    node(int k)
    {
        prev=next=NULL;
        data=k;
    }
};
class DLL
{
    public:
    node *head;
    DLL(){ head=NULL; }
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
            new_node->prev=ptr;
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
    }
    void push(node *&head,int data,int position)
    {
        node *new_node=new node(data);
        node *ptr=head;
        int n=1;
        if(position==1)
        {
            new_node->next=head;
            head->prev=new_node;
            head=new_node;
            return;
        }
        while(n<position-1)
        {
            ptr=ptr->next;
            n++;
        }
        new_node->next=ptr->next;
        ptr->next->prev=new_node;
        ptr->next=new_node;
        new_node->prev=ptr;
    }
    void delet(node *&head,int key)
    {
        node *ptr=head;
        int n=1;
        if(key==1)
        {
            head=head->next;
            head->next->prev=NULL;
            free(ptr);
            return;
        }
        while(n<key)
        {
            ptr=ptr->next;
            n++;
        }
        node *qtr=ptr;
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(qtr);
    }
};
int main() {
    node *head=NULL;
    DLL d1;
    d1.insert(head,1);
    d1.insert(head,2);
    d1.insert(head,3);
    d1.insert(head,4);
    d1.push(head,5,4);
    d1.display(head);cout<<endl;
    d1.delet(head,1);
    d1.display(head);cout<<endl;
 return 0;
}