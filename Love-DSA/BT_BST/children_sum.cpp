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
bool isparentsum(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            int sum = 0;
            q.pop();
            if (node->left)
            {
                sum += node->left->val;
                q.push(node->left);
            }
            if (node->right)
            {
                sum += node->right->val;
                q.push(node->right);
            }
            if (!node->left && !node->right)
                sum = node->val;

            if (sum != node->val)
                return false;
        }
    }
    return true;
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