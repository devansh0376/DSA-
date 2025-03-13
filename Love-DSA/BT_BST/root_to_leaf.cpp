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

void solve(Node *node,vector<vector<int>> &ans,vector<int> v)
 {
     if(node==NULL)
     return ;
     v.push_back(node->val);
     if(node->left==NULL && node->right==NULL)
     {
         ans.push_back(v);
         return;
     }
     solve(node->left,ans,v);
     solve(node->right,ans,v);
     v.pop_back();
 }
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<int> v;
    vector<vector<int>> ans;
    solve(root,ans,v);
    return ans;
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