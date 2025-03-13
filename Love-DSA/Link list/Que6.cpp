#include<bits/stdc++.h>
using namespace std;
//check that link list is palimdrome or not
// Approch 1 :creat copy of the link list (l1) and revrese it l1 and compare it with original link list
//Approch 2 :reach the middle node do partion in two link list. l1 contains element before middle node and l2 
// contains element after middle node
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
    node *getmid(node *head)
    {
        node *fast,*slow;
        fast=slow=head;
        if(fast->next->next==NULL)
        return head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {      
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    node *reverse(node *&head)
    {
        node *curr=head;
        node *forward=NULL;
        node *prev=NULL;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;curr=forward;
        }
        return prev;
    }
    bool compare(node *l1,node *l2)
    {
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->data!=l2->data)
            return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
    bool ispalindrome(node *&head)
    {
        if(head==NULL)return false;
        if(head->next==NULL)return true;
        node *mid=getmid(head);
        node *l2=mid->next;
        mid->next=NULL; // break the link 
        node *l1=head; // l1 :head to middle and l2:middle's next to last node
        l2=reverse(l2);
        bool ans=compare(l1,l2);
        return ans;
    }
};
int main() {
    node *head=NULL;
    SLL s1;
    s1.insert(head,1);
    s1.insert(head,2);
    s1.insert(head,3);
    //s1.insert(head,4);
    s1.display(head);cout<<endl;
    node *temp=s1.getmid(head);
    cout<<temp->data<<endl;
    bool x=s1.ispalindrome(head);
    if(x)cout<<"YES";
    else cout<<"NO";
 return 0;
}