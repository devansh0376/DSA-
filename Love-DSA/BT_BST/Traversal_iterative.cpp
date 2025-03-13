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

void preorder(vector<int> &pre,Node*root)
{
    //root left right
    //push first right then left.
    stack<Node *>s;
    s.push(root);
    while(s.size()>0)
    {
        root=s.top();
        s.pop();
        pre.push_back(root->val);
        if(root->right)s.push(root->right);
        if(root->left)s.push(root->left);
    }
}
void inorder(vector<int>&ino,Node*node)
{
    //left root right
    stack<Node *>s;
    while(1)
    {
        if(node)
        {
            s.push(node);
            node=node->left;
        }
        else
        {
            if(s.size()==0)break;
            node=s.top();
            s.pop();
            ino.push_back(node->val);
            node=node->right;
        }
    }
}
void postorder(vector<int>&post,Node*root)
{
    stack<Node *>s1,s2;
    s1.push(root);
    while(s1.size()>0)
    {
        root=s1.top();
        s1.pop();
        s2.push(root);
        if(root->left)s1.push(root->left);
        if(root->right)s1.push(root->right);
    }
    while(s2.size()>0)
    {
        post.push_back(s2.top()->val);
        s2.pop();
    }
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
        else
        temp->left=NULL;
        if (right < n)
        temp->right = new Node(v[right]);
        else
        temp->left=NULL;
        q.push(temp->left);
        q.push(temp->right);
    }
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
    Node *root=NULL;
    build2(root,v);
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