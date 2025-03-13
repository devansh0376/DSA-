#include<bits/stdc++.h>
using namespace std;
//Merge two sorted link list
/*
i/p: l1: 1 2 4 ,l2: 1 2 3
o/p: 1 1 2 2 3 4
->we create one dummy node with value -1. and every time we check from both link list which value is small.
->node with smaller value link with the dummy node and at the last we return dummy->next;
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
    node *merge_two_sortedLL(node *&l1,node *&l2)
    {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        node *dummy=new node(-1);
        node *ptr=dummy;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->data<l2->data)
            {
                node *new_node=new node(l1->data);
                ptr->next=new_node;
                l1=l1->next;
            }
            else
            {
                node *new_node=new node(l2->data);
                ptr->next=new_node;
                l2=l2->next;
            }
            ptr=ptr->next;
        }
        if(l1)
        ptr->next=l1;
        if(l2)
        ptr->next=l2;
        return dummy->next;
    }
};
int main() {
    node *l1,*l2;
    l1=l2=NULL;
    SLL s1;
    s1.insert(l1,8);
    s1.insert(l1,9);
    s1.insert(l1,11);
    s1.insert(l2,4);
    s1.insert(l2,9);
    s1.insert(l2,12);
    s1.display(l1);cout<<endl;
    s1.display(l2);cout<<endl;
    node *merge_LL=s1.merge_two_sortedLL(l1,l2);
    s1.display(merge_LL);cout<<endl;
 return 0;
}