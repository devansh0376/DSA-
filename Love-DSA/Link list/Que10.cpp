#include<bits/stdc++.h>
using namespace std;
// ADD two LL
/*
->there are two varient of this question,fisrt is add one number to LL and second is add two Linklist
->code are same, in first varient carry=0,and second varient carry=1;
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
    node *reverse(struct node* head)
    {
        node *curr=head,*prev=NULL,*forwad;
        while(curr)
        {
            forwad=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forwad;
        }
        return prev;
    }
    node* addTwoLists(struct node* l1, struct node* l2)
    {
        // code here
        l1=reverse(l1);
        l2=reverse(l2);
        node *dummy=new node(-1);
        node *ptr=dummy;
        int carry=0;
        while(l1 || l2 || carry)
        {
            int sum=0;
            if(l1)
            {
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ptr->next=new node(sum);
            ptr=ptr->next;
        }
        node *new_head=dummy->next;
        return reverse(new_head);
    }
};
int main() {
    node *head=NULL;
    SLL s1;
    s1.insert(head,1);
    s1.insert(head,2);
    s1.insert(head,3);
    s1.insert(head,4);
    s1.display(head);cout<<endl;
 return 0;
}