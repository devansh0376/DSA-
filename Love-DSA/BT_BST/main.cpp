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
void *build2(Node *&root, vector<int> v)
{
    int n = v.size();
    queue<Node*> q;
    q.push(root);
    for (int i = 0; i < (n / 2); i++)
    {
        struct Node *temp = q.front();
        q.pop();
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        if (left < n)
            temp->left = new Node(v[left]);
        if (right < n)
            temp->right = new Node(v[right]);
        q.push(temp->left);
        q.push(temp->right);
    }
}
void creat_tree(Node *&root,vector<int>v)
{
    //root=build1(v,0);
    build2(root,v);
}
int main()
{
    Node *root=NULL;
    vector<int>v;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        v.push_back(i);
    }
    creat_tree(root,v);
    return 0;
}