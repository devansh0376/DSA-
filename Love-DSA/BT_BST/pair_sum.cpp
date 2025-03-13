/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

*/
#include <bits/stdc++.h>
using namespace std;
// here are the three varient of this problem 

class Node  
{
public:
    int val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
Node *build1(vector<int> v, int i)
{
    if (v[i] == -1)
        return NULL;
    if (i >= v.size())
        return NULL;
    Node *root = new Node(v[i]);
    root->left = build1(v, (2 * i) + 1);
    root->right = build1(v, (2 * i) + 2);
    return root;
}

//here we use BST iterator concept.in BST iterator we get next element.in BST iterator we push all left element in the stack then if we need next element we return s.top() value and go right and call pushall funtion this push all left element
//now what if we need before element we just do reverse thing we make push all funtion which push all right element,if we want before element we return s.top() value and go left and call push all funtion which push all right element

class BSTIterator {
public:
    stack<Node*>s;
    bool reverse=true;
    BSTIterator(Node* node,bool is_reverse) {
        reverse=is_reverse;
        pushall(node);
    }
    
    bool hasNext() {
        return !s.empty();
    }
    int next() {
        Node *tmpNode = s.top();
        s.pop();
        if(reverse)
        pushall(tmpNode->right);
        else
        pushall(tmpNode->left);
        return tmpNode->val;
    }
    
    void pushall(Node *node)
    {
        while(node)
        {
            s.push(node);
            if(reverse)
            node=node->left;
            else
            node=node->right;
        }
    }
};