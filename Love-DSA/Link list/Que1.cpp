#include<bits/stdc++.h>
using namespace std;
// reverse link list
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
    node *reverse(node *&head)
    {
        // itteritive method
        /*
        node *curr=head,*prev=NULL;
        node *forward; // for move curr pointer to next position
        while(curr!=NULL)
        {
            forward=curr->next; // to move curr node we store next pointer
            curr->next=prev; // chaning link to previous
            prev=curr;curr=forward; // move pointer to next node
        }x
        return prev;
        */
       // recursive method
       if(head==NULL || head->next==NULL) // base condition
       return head;
       node *ptr=reverse(head->next);
       node *front=head->next  ;
       front->next= head;
       head->next=NULL;
       return ptr;
    //    head->next->next=head; // assign link to previous
    //    head->next=NULL;
       
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
    node *new_head=s1.reverse(head);
    s1.display(new_head);
 return 0;
}