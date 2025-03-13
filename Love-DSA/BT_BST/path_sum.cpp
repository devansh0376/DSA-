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

//first : given BT and one target sum return true or false if there is a path from root to leaf node and it's sum==target
bool check(Node *node,int k)
{
    if(node==NULL)
    return false;
    k = k - node->val;
    if(k==0 && node->left==NULL  && node->right==NULL)
    return true;
    bool l=check(node->left,k);
    bool r=check(node->right,k);

    return l || r;
}
bool hasPathSum(Node* root, int targetSum) {
    return check(root,targetSum);
}
//second: same as above but here we need to print all path from root to leaf whose sum equal to taeget
void solve(Node *node,int sum,int k,vector<int> v,vector<vector<int>> &ans)
{
    if(node==NULL)
    return;
    sum=sum+node->val;
    v.push_back(node->val);
    if(sum==k && node->left==NULL && node->right==NULL)
    {
        ans.push_back(v);
        sum=0;
        return;
    }
    solve(node->left,sum,k,v,ans);
    solve(node->right,sum,k,v,ans);
    v.pop_back();
}
vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<int>v;
    vector<vector<int>> ans;
    int sum=0;
    solve(root,sum,targetSum,v,ans);
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