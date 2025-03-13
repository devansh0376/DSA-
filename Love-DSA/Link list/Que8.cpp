#include<bits/stdc++.h>
using namespace std;
// sort the link list
/*
->in this question we use concept of mearge sort,in array we have index so there work quite simple.
->we divede LL in two parts. then we ,mearge it.first we get middle of LL and 
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one element
        if (!head || !head->next) {
            return head;
        }
        
        // Step 1: Split the list into two halves
        ListNode* mid = getMiddle(head);    // Find the middle of the list
        ListNode* left = head;              // Left half starts from head
        ListNode* right = mid->next;        // Right half starts from the node after mid
        mid->next = nullptr;                // Split the list into two halves
        
        // Step 2: Recursively sort both halves
        left = sortList(left);
        right = sortList(right);
        
        // Step 3: Merge the two sorted halves
        return merge(left, right);
    }
    
private:
    // Helper function to find the middle of the linked list
    ListNode* getMiddle(ListNode* head) 
    {
        if (!head) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // Fast moves two steps, slow moves one step
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;  // slow is now at the middle
    }
    
    // Helper function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) 
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) 
        {
            if (l1->val < l2->val) 
            {
                tail->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Append the remaining nodes from either l1 or l2
        //tail->next = l1 ? l1 : l2;
        if(l1==NULL)tail->next=l2;
        else tail->next=l1;
        
        return dummy.next;  // Return the merged list starting from the node after dummy
    }
};

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