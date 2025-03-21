#include<bits/stdc++.h>
using namespace std;
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
    void push(node *&head,int data,int position)
    {
        node *new_node=new node(data);
        if(head==NULL)
        {
            insert(head,data);
        }
        else if(position==1)
        {
            new_node->next=head;
            head=new_node;
        }
        else
        {
            
            node *ptr=head;
            int n=1;
            while(n<position-1)
            {
                ptr=ptr->next;
                n++;
            }
            new_node->next=ptr->next;
            ptr->next=new_node;
        }
    }
    void delet(node *&head,int key)
    {
        node *ptr=head;
        node *qtr=head->next;
        int n=1;
        if(key==1)
        {
            head=head->next;
            free(ptr);
            return;
        }
        while(n<key-1)
        {
            ptr=ptr->next;
            qtr=qtr->next;
            n++;
        }
        ptr->next=qtr->next;
        free(qtr);
    }
};
int main() {
    node *head=NULL;
    SLL s1;
    s1.insert(head,1);
    s1.insert(head,2);
    s1.insert(head,3);
    s1.insert(head,4);
    //s1.push(head,5,3);
    s1.display(head);cout<<endl;
    s1.delet(head,1);
    s1.display(head);
 return 0;
}