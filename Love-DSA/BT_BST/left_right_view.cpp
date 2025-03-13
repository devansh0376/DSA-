#include <bits/stdc++.h>
using namespace std;
// left view of BT
/*
->here we need to print first node of every level.so we make one varible and add node->val and make it false.
*/

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
vector<int> leftSideView(Node *root)
{
    vector<int> v;
    // solve(node,0,v);
    if (root == NULL)
        return v;
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int n = q.size();
        int f = 1;
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            if (f)
            {
                f=0;
                v.push_back(node->val);
            }
            if (node->left)
            q.push(node->left);
            if (node->right)
            q.push(node->right);
        }
    }
    return v;
}
vector<int> rightSideView(Node *root)
{
    vector<int> v;
    // solve(node,0,v);
    if (root == NULL)
        return v;
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            if (i == n - 1)
            {
                v.push_back(node->val);
            }
            if (node->left)
            q.push(node->left);
            if (node->right)
            q.push(node->right);
        }
    }
    return v;
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