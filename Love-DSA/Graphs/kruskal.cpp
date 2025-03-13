#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<int> parent, rank;

int find(int x)
{
    if (x == parent[x])
        return x;
    else
    return parent[x] = find(parent[x]); // with path compression
    // return find(parent[x])
}
void Union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
        return;

    if (rank[x_parent] > rank[y_parent]) // x become papa
        parent[y_parent] = x_parent;
    else if (rank[y_parent] > rank[x_parent]) // y become papa
        parent[x_parent] = y_parent;
    else
    {
        parent[x_parent] = y_parent; // anyone can be papa
        rank[y_parent]++;            // here y become papa so increse y's rank by 1
    }
}
int spanningTree(int V, vector<vector<int>> adj[])
{
    for (int i = 0; i < V; i++)
    {
        parent.push_back(i);
        rank.push_back(0);
    }
    vector<vector<int>> v;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int node = it[0];
            int wt = it[1];

            v.push_back({wt, i, node});
        }
    }
    sort(v.begin(), v.end());

    int sum = 0;

    for (auto it : v)
    {
        int u = it[1];
        int v = it[2];
        int wt = it[0];

        int parent_u = find(u);
        int parent_v = find(v);

        if (parent_u != parent_v)
        {
            sum += wt;
            Union(u, v);
        }
    }
    return sum;
}
int main()
{
    return 0;
}