#include<bits/stdc++.h>
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

void preorder(vector<int> &pre,Node*node)
{
    if(node==NULL)
    return;
    pre.push_back(node->val);
    preorder(pre,node->left);
    preorder(pre,node->right);
}
void inorder(vector<int>&ino,Node*node)
{
    if(node==NULL)
    return ;
    inorder(ino,node->left);
    ino.push_back(node->val);
    inorder(ino,node->right);
}
void postorder(vector<int>&post,Node*node)
{
    if(node==NULL)
    return ;
    postorder(post,node->left);
    postorder(post,node->right);
    post.push_back(node->val);
}
vector<vector<int>> getTreeTraversal(Node *root){
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>pre,ino,post;
    preorder(pre,root);
    inorder(ino,root);
    postorder(post,root);
    ans={pre,ino,post};
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
int main() {
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        v.push_back(x);
    }
    Node *root=build1(v,0);
    vector<vector<int>>ans=getTreeTraversal(root);
    cout<<endl;
    int x=1;
    for(auto i:ans)
    {
        if(x==1)cout<<"preorder"<<endl;
        if(x==2)cout<<"inorder"<<endl;
        if(x==3)cout<<"postorder"<<endl;
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        x++;
        cout<<endl;
    }

 return 0;
}