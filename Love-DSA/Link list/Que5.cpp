#include<bits/stdc++.h>
using namespace std;
// remove dublicate from link list
/*
->for sorted just traverse and check the element is mach or not if mach delet it
->for unsorted array we use map. we check every element if it is in map delet it
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
    void delet_soredLL(node *&head)
    {
        node *ptr=head;
        while(ptr->next !=NULL)
        {
            if(ptr->data==ptr->next->data)
            {
                node *temp=ptr->next;
                ptr->next=temp->next;
                free(temp);
            }
            else
            ptr=ptr->next;
        }
    }
    void delet_unsortedLL(node *&head)
    {
        map<int,bool>m;
        node *ptr=head;
        m[ptr->data]=true;
        node *qtr=ptr;
        ptr=ptr->next;
        while(ptr!=NULL)
        {
            if(m[ptr->data]==true)
            {
                qtr->next=ptr->next;
                free(ptr);
            }
            else
            {
                m[ptr->data]=true;
                qtr=ptr;
            }
            ptr=qtr->next;
        }
    }
};
int main() {
    node *head=NULL;
    SLL s1;
    s1.insert(head,4);
    s1.insert(head,8);
    s1.insert(head,2);
    s1.insert(head,8);
    s1.delet_unsortedLL(head);
    s1.display(head);
 return 0;
}