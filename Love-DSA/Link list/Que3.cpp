#include<bits/stdc++.h>
using namespace std;
// rotate in k group 
/*
i/p :1 2 3 4 5 ,k=3
o/p :4 5 1 2 3 
->here we use two steps. in first step we reach last node of LL. and in second step we reach kth node of LL.
->now simply we link kth+1 node to first node. and point kth node to NULL
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
    node *rotate(node *&head,int k)
    {
        //step 1
        node *qtr=head;
        while(qtr->next!=NULL)
        qtr=qtr->next;
        //step 2
        node *ptr=head;
        int n=1;
        while(n<k)
        {
            ptr=ptr->next;
            n++;
        }
        qtr->next=head; //linking last node to first node
        node *new_node=ptr->next; // kth+1 node
        ptr->next=NULL;

        return new_node;
    }
};
int main() {
    SLL s1;
    node *head=NULL;
    s1.insert(head,1);
    s1.insert(head,2);
    s1.insert(head,3);
    s1.insert(head,4);
    s1.insert(head,5);
    s1.display(head);
    cout<<endl;
    int k;cin>>k;
    node *new_head=s1.rotate(head,k);
    s1.display(new_head);
 return 0;
}