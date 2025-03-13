#include <bits/stdc++.h>
using namespace std;
/*
                   1
                /    \
               2      7
              /         \  ->boundry ordered traversal : 1,2,3,4,5,6,10,11,9,8,7
             3           8
              \         /
               4       9
              /  \   /  \
             5    6 10   11
*/
/*
->for this problem we keep all none leaf node of left and right. keep all leaf node different
->here we need four funtion fist for add left side node then one for leaf node,one for right side nodes and one for check for leaf node.
*/
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
bool isleaf(Node *node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}
void addleft(Node *root, vector<int> &ans)
{
    Node *node = root->left;
    while (node)
    {
        if (!isleaf(node))
            ans.push_back(node->data);

        if (node->left)
            node = node->left;
        else
            node = node->right;
    }
}
void addright(Node *root, vector<int> &ans)
{
    Node *node = root->right;
    vector<int> v;
    while (node)
    {
        if (!isleaf(node))
            v.push_back(node->data);
        if (node->right)
            node = node->right;
        else
            node = node->left;
    }
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
        ans.push_back(v[i]);
}
void addleaf(Node *root, vector<int> &ans)
{
    if (isleaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        addleaf(root->left, ans);
    if (root->right)
        addleaf(root->right, ans);
}   
vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    if (isleaf(root))
        return ans;

    addleft(root, ans);
    addleaf(root, ans);
    addright(root, ans);

    return ans;
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