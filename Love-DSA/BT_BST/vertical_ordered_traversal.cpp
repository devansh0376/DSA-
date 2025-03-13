#include <bits/stdc++.h>
using namespace std;
/*
vertical order
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
vector<vector<int>> verticalTraversal(Node *root)
{
    map<int, map<int, multiset<int>>> m;       // map<verix,map<level,value>> , m[vertix][level]=value
    queue<pair<Node *, pair<int, int>>> q; // queue<node,pair<vertix,level>>
    q.push({root, {0, 0}});
    while (q.size() > 0)
    {
        auto p = q.front();
        q.pop();
        Node *node = p.first; // node
        int x = p.second.first;   // vertix;
        int y = p.second.second;  // level
        /*
        map<key,value>    | map<key,map<key,value>
        if map<int,int>m  | map<int,map<int,int>>m
        m[key]=value      |m[key][key]=value
       */
        m[x][y].insert(node->val); // vertix level value
        if (node->left)
            q.push({node->left, {x - 1, y + 1}}); // level++,vertix--
        if (node->right)
            q.push({node->right, {x + 1, y + 1}}); // level++,vertix++
    }
    vector<vector<int>> ans;
    for (auto i : m)
    {
        vector<int> temp;
        for (auto j: i.second) // i.second=map<vertix,level>
        {
            temp.insert(temp.end(), j.second.begin(), j.second.end()); // insert all values, 0 : 1.6,9,10
        }
        ans.push_back(temp);
    }
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
    root = build1(v, 0);
    return 0;
}