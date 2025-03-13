#include <bits/stdc++.h>
using namespace std;
// zig zag level order traveral
/*
->here we have to impliment level order with some change.here we firts print root and then go right to left then print left to right 
->so for this we kept we kept one varible . if f=1 print go right to left ,f=0 then print  left to right 
->for store this we make one vector. if f=1 then index=i else index of vector is n-1-i
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
vector<vector<int>> zigzag(Node *root)
{
    queue<Node *>q;
    q.push(root);
    int f=1;
    vector<vector<int>>ans;
    if(root==NULL)
    return ans;
    while(q.size()>0)
    {
        int size=q.size();
        vector<int>v(size);
        for(int i=0;i<size;i++)
        {
            Node *node=q.front();
            q.pop();
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
            int idx=f ? i : size-i-1;
            v[i]=node->val;
        }
        f=!f;

        ans.push_back(v);
    }
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
    root=build1(v, 0);
    return 0;
}