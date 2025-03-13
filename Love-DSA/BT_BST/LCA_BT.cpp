#include <bits/stdc++.h>
using namespace std;
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
// if return type is not node and node's value given.so we have to first find that nodes with level order trevesal
void findnode(Node *root, int x, int y, Node *&p,Node *&q)
{
    queue<Node *> que;
    que.push(root);
    while (que.size() > 0)
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = que.front();
            que.pop();
            if (x == node->val)
                p = node;
            if (y == node->val)
                q = node;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
}

// if node return type is node
Node *lca(Node *node, int p, int q)
{
    // Your code here
    if (node == NULL || node->val == p || node->val == q)
        return node;
    Node *left = lca(node->left, p, q);
    Node *right = lca(node->right, p, q);
    if (left == NULL)
        return right; // go right
    else if (right == NULL)
        return left; // go left
    else             // noth are NULL so we found our result.
        return node;
}
int lowestCommonAncestor(Node *root, int x, int y)
{
	//    Write your code here
    Node * p,*q;
    findnode(root,x,y,p,q);
    Node * ans=lca(root,p->val,q->val);
    return ans->val;
}
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
int main()
{
    Node *root = NULL;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    root = build1(v, 0);
    return 0;
}