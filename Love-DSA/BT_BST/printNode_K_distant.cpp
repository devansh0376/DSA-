#include <bits/stdc++.h>
using namespace std;
// print all node at distant k from given node
/*
->for this we should have parent point bcoz we have access node upword side.so first we make parent pointer.
->In step two we increase our distant from given node and push nodes in queue. if dist==k we break loop
and tranfer all nodes in vector from queue.
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
void markparent(Node *root, unordered_map<Node *, Node *> &parent_track)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        Node *node = q.front();
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
}
vector<int> distanceK(Node *root, Node *target, int k)
{
    // make parent pointer
    unordered_map<Node *, Node *> parent_track;
    markparent(root, parent_track);
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int dist = 0;
    while (q.size() > 0)
    {
        int size = q.size();
        // dist++;
        if (dist++ == k)
            break;
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
            }
            // move right
            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            // move up: parent
            if (parent_track[node] && !visited[parent_track[node]])
            {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }
    vector<int> v;
    while (q.size() > 0)
    {
        Node *node = q.front();
        q.pop();
        v.push_back(node->val);
    }
    return v;
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