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
/*
->use concept of fisrt visit,second visit and third visit
->first visit push element in preorder(root left right)
->second visit push element in inorder(left root right)
->third visit push element in postorder(left right root)
*/
void get_all(vector<int> &pre,vector<int> &ino,vector<int> &post,Node *root)
{
    stack<pair<Node*,int>>s;
    s.push({root,1});
    while(s.size()>0)
    {
        auto i=s.top();
        s.pop();
        if(i.second==1)
        {
            pre.push_back(i.first->val);
            i.second++;
            s.push(i);
            if(i.first->left!=NULL)
            s.push({i.first->left,1});
        }
        else if(i.second==2)
        {
            ino.push_back(i.first->val);
            i.second++;
            s.push(i);
            if(i.first->right!=NULL)
            s.push({i.first->right,1});
        }
        else 
        {
            post.push_back(i.first->val);
        }
    }
    
}
vector<vector<int>> getTreeTraversal(Node *root){
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>pre,ino,post;
    get_all(pre,ino,post,root);
    ans={pre,ino,post};
    return ans;
}
int main()
{
    vector<int>v;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        v.push_back(x);
    }
    Node *root=build1(v,0);
    vector<vector<int>>ans=getTreeTraversal(root);
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