#include <bits/stdc++.h>
using namespace std;
// we have to find max sum via path.this problem is looks like find diameter.In that problem we do 1+max(lh,rh)
/*
->here we have to sum all node from node a to node b.here we find left subtree value and right subtree  valu and
maximize(node->val+ max(left,right))
->for this we kept one varible and pass it by reference.
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
int maxsum(Node *node, int &mx)
{
    if (node == NULL)
    return 0;
    int leftsum = max(0, maxsum(node->left, mx));
    int rightsum = max(0, maxsum(node->right, mx));
    mx = max(mx, leftsum + rightsum + node->val);
    return node->val + max(leftsum, rightsum);
}
int maxPathSum(Node *node)
{
    int sum = INT_MIN;
    if (node->left == NULL && node->right == NULL)
    return node->val;
    maxsum(node, sum);
    return sum;
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