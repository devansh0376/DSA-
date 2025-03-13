#include<bits/stdc++.h>
using namespace std;
// reverse in k group 
/*
i/p :3 2 7 8 9 11 ,k=2
o/p :2 3 8 7 11 9
->here we use recursion. we reverse first K group and rest Link list will reverse with the help of recursion
->after reverse k group we call recursion for head->next. 
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
    node *reverse_kgroup(node *&head,int k)
    {
        node *curr=head,*prev=NULL,*forward;
        int n=0;
        //step 1:reverse first k group
        while(curr!=NULL && n<k)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            n++;
        }
        //step 2:recursion
        if(forward!=NULL)
        head->next=reverse_kgroup(curr,k);
        //step 3:reverse the head of the link lst
        return prev;
    }
};
int main() {
    SLL s1;
    node *head=NULL;
    //1 2 2 4 5 6 7 8
    s1.insert(head,1);
    s1.insert(head,2);
    s1.insert(head,2);
    s1.insert(head,4);
    s1.insert(head,5);
    s1.insert(head,6);
    s1.insert(head,7);
    s1.insert(head,8);
    s1.display(head);
    cout<<endl;
    int k;cin>>k;
    node *new_head=s1.reverse_kgroup(head,k);
    s1.display(new_head);
 return 0;
}