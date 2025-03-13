#include <bits/stdc++.h>
using namespace std;
// Diameter of BT : longest path between any two nodes
/*
->just maximize the height(left subtree)+height(right subtree)
->first approch we think that we go to every node and find left height and right height and maximize it
->but here we have to call funtion for all node and we have to travers every node so if number of node is Time complexity is 0(n*n)

->Insted of this we find it in 0(n). when we find our height , we kept one variable and do mx=max(mx,lh+rh)
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
int findmax(Node *node, int &mx)
{
    if (node == NULL)
    return 0;
    int lh = findmax(node->left, mx);
    int rh = findmax(node->right, mx);
    mx = max(mx, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(Node *node)
{
    int diameter = 0;
    findmax(node, diameter);
    return diameter;
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
void creat_tree(Node *&root, vector<int> v)
{
    root = build1(v, 0);
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
        v.push_back(i);
    }
    creat_tree(root, v);
    return 0;
}