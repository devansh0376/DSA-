#include <bits/stdc++.h>
using namespace std;
// we have to find maxdepth of BT.
/*
->we go to every node take 1+max(heigh of left subtree,heigh of right subtree)
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
//native solution 
int heightBT(Node *node)
{
    if (node == NULL)
        return 0;
    int lh = heightBT(node->left);
    int rh = heightBT(node->right);
    return 1 + max(lh, rh);
}
bool isBalancedBT(Node *root){
    // Write your code here.
    if(root==NULL)
    return true;

    int l=heightBT(root->left);
    int r=heightBT(root->right);

    if(abs(l-r)>1)
    return false;
    bool left=isBalancedBT(root->left);
    bool right=isBalancedBT(root->right);

    if(!left || !right)
    return false;

    return true;
}
/*
->in this question we have to find that BT is balance or not;
->is height(left)-height(right)<=1 :>this is balance BT
*/
int height(Node * node)
{
    if(node==NULL)
    return true;
    int lh=height(node->left);
    int rh=height(node->right);
    if(abs(rh-lh)>1)
    return -1;
    if(lh==-1 || rh==-1)
    return -1;
    return 1+max(lh,rh);
}
bool isBalanced(Node* root) {
    int ans=height(root);
    if(ans==-1)
    return false;
    else
    return true;
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
    root=build1(v, 0);
    cout << height(root);
    return 0;
}