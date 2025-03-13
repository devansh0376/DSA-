/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(0), left(nullptr), right(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
// build binary tree
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
class BSTIterator {
public:
    stack<Node*>s;
    BSTIterator(Node* node) {
        pushall(node);
    }
    
    
    bool hasNext() {
        return !s.empty();
    }
    int next() {
        Node *tmpNode = s.top();
        s.pop();
        pushall(tmpNode->right);
        return tmpNode->val;
    }
    
    void pushall(Node *node)
    {
        while(node)
        {
            s.push(node);
            node=node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */