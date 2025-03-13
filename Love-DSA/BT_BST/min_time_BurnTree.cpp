#include <bits/stdc++.h>
using namespace std;
//minimum time to burn binary tree.(we can burn all connected node in one second)
/*
->In previous question we need to return all nodes  from given node at k distant.so we move left,right and up.when (dist==k) we retun queue's element.
->In this we need to burn nodes from given node,so we move left,right and up.and for this we need one unit of time.once we done this we do this again
*/
// if we want to just visit to every node we don't use for loop kind thing in while loop this when we want to travers level vise
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
Node* markparent(Node *root, unordered_map<Node *, Node *> &parent_track,int x)
{
    queue<Node *> q;
    q.push(root);
    Node *target;
    while (q.size() > 0)
    {
        Node *node = q.front();
        if(node->val==x)
        target=node;
        q.pop();
        if (node->left)
        {
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
    return target;
}
int time_to_burn(Node *root, int x)
{
    // make parent pointer
    unordered_map<Node *, Node *> parent_track;
    Node *target=markparent(root, parent_track,x);
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int time = 0;
    while (q.size() > 0)
    {
        int size = q.size();
        int burn=0;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            // mark left and right node if they don't mark as visited
            // move left
            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
                burn=1;
            }
            // move right
            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
                burn=1;
            }
            // move up: parent
            if (parent_track[node] && !visited[parent_track[node]])
            {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
                burn=1;
            }
        }
        if(burn)time++;
    }
    return time;
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