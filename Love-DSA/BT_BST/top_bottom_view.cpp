#include <bits/stdc++.h>
using namespace std;
//top view of BT
/*
->here we use same line concept.here we need every first node of line.so we creat one queue of (node,line)
and creat one map<line,value> to track the line if visited or not. we need only first time visited value.
so we insert value in map if it is not in map.after all value inserted in map. we add value in out ans vector.
->First we insert all lines and value.then we travers in increse ordered and add value in our ans
*/
// bottom view of BT
/*
->here we use same line concept.here we need every last node of line.so we creat one queue of (node,line)
and creat one map<line,value> to track the line if visited or not.we update every time value in map for every line so in the last we reach last node of every line.after all value inserted in map. we add value in out ans vector.
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
vector<int> bottom_view(Node *root)
{
    queue<pair<Node*,int>>q;// q<node,line>
    map<int,int>m; // m<line,value>
    q.push({root,0});
    while(q.size()>0)
    {
        auto it=q.front();
        q.pop();
        Node *node=it.first;
        int line=it.second;
        m[line]=node->val;
        if(node->left)
        q.push({node->left,line-1});
        if(node->right)
        q.push({node->right,line+1});
    }
    vector<int>ans;
    for(auto i:m)
    ans.push_back(i.second);

    return ans;
}
vector<int> top_view(Node *root)
{
    queue<pair<Node*,int>>q;// q<node,line>
    map<int,int>m; // m<line,value>
    q.push({root,0});
    while(q.size()>0)
    {
        auto it=q.front();
        q.pop();
        Node *node=it.first;//node
        int line=it.second;//line
        if(m.find(line)==m.end())
        m[line]=node->val;
        if(node->left)
        q.push({node->left,line-1});
        if(node->right)
        q.push({node->right,line+1});
    }
    vector<int>ans;
    for(auto i:m)
    ans.push_back(i.second);

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