#include<bits/stdc++.h>
using namespace std;
// find intersection point of LL 
/*
l1 :     4 - 1 
              \
               8 - 4 - 1  intersection point is  : 8
              /
l2 : 5 - 6 - 1 
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
    node *find_intersection(node *h1,node *h2)
    {
        /*while(h1)
        {
            node *ptr=h2;
            while(ptr)
            {
                if(ptr==h1)
                return ptr;
                ptr=ptr->next;
            }
            h1=h1->next;
        }
        return NULL;*/
        //second method : better
        /*unordered_map<node*, int> m;
        while(h1)
        {
            m[h1]++;
            h1=h1->next;
        }
        while(h2)
        {
            if(m[h2]>0)
            return h2;
            h2=h2->next;
        }
        return NULL;*/
        //third method
        /*int l1=get_lenght(h1);
        int l2=get_lenght(h2);
        node *temp,*ptr,*qtr;
        int dif=abs(l1-l2);
        if(l1>l2)
        {
            temp=h1;
            qtr=h2;
        }
        else if(l2>l1)
        {
            temp=h2;
            qtr=h1;
        }
        else
        {
            temp=h1;
            ptr=h1;
            qtr=h2;
        }
        while(dif>0)
        {
            temp=temp->next;
            dif--;
        }
        ptr=temp;
        while(ptr && qtr)
        {
            if(ptr==qtr)
            return ptr;
            ptr=ptr->next;
            qtr=qtr->next;
        }
        return NULL;*/
        //forth method : two pointer
        /* If any node dummy node becomes NULL we assgign to head of another LL and after second iteretion d1 and d2 points to same */
        node *d1=h1,*d2=h2;
        while(d1!=d2)
        {
            if(!d1)d1=h2;
            else
            d1=d1->next;
            if(!d2)d2=h1;
            else
            d2=d2->next;
        }
        return d1;
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