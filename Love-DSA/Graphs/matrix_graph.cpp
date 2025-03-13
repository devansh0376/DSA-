#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*
->here in problem matrix is given and they ask following pattern question
-count the connected component,rotten oranges,Surrounded Regions,Number of Distinct Islands
->in this problem we can solve with bfs or dfs , do what comes in mind. 
*/
//547. Number of Provinces
/*
void dfs(vector<int> adj[],int node,int vis[])
    {
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(vis[i]==0)
            dfs(adj,i,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& mat)
    {
        int n=mat.size(),m=mat[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int vis[n];
        for(int i=0;i<n;i++)
        vis[i]=0;
        int Provinces=0;
        //count the disconnect components
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis);
                Provinces++;
            }
        }
        //using bfs
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=true)
            {
                queue<int>q;
                q.push(i);
                while(q.size()>0)
                {
                    int x=q.front();
                    q.pop();
                    for(auto it:adj[x])
                    {
                        if(vis[it]!=1)
                        {
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
                Provinces++;
            }
        }
        
    return Provinces;
    }
*/
//994. Rotting Oranges
/*
int orangesRotting(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size();
    if(grid.empty()) return 0;
    queue<pair<int,int>>q;
    int total_cnt=0,rotten_cnt=0,time=0;
    //push all rotten orange in queue 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            q.push({i,j});
            if(grid[i][j]!=0)
            total_cnt++;
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    //pop rotten orange go all four direction if any fresh orange mark it rotten 
    //simple bfs
    while(q.size()>0)
    {
        int size=q.size();
        rotten_cnt+=size;
        while(size--)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=x+dx[i];
                int nc=y+dy[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]!=1)
                continue;

                grid[nr][nc]=2;
                q.push({nr,nc});
            }
        }
        if(q.size()>0)
        time++;
    }
    return rotten_cnt==total_cnt ? time : -1;
    }
*/
//733. Flood Fill
/*
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldcolor=image[sr][sc];
        image[sr][sc]=color;
        if(oldcolor == color) return image;
        //simple bfs
        while(q.size()>0)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m || image[nr][nc]!=oldcolor)
                continue;
                image[nr][nc]=color;
                q.push({nr,nc});
            }
        }

        return image;
    }
*/
//130. Surrounded Regions
//in this kind problem you need to travers or track the boundry of the matrix
/*
void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis,
    int drow[],int dcol[])
    {
        vis[row][col]=1;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && vis[nrow][ncol]==0 && grid[nrow][ncol]=='O')
            dfs(nrow,ncol,grid,vis,drow,dcol);
        }
    }
    void solve(vector<vector<char>>& grid) {
       int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //mark first row and last row
        for(int j=0;j<m;j++)
        {
            if(vis[0][j]==0 && grid[0][j]=='O')
            dfs(0,j,grid,vis,drow,dcol);
            if(vis[n-1][j]==0 && grid[n-1][j]=='O')
            dfs(n-1,j,grid,vis,drow,dcol);
        }
        //mark fist column and last column
        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0 && grid[i][0]=='O')
            dfs(i,0,grid,vis,drow,dcol);
            if(vis[i][m-1]==0 && grid[i][m-1]=='O')
            dfs(i,m-1,grid,vis,drow,dcol);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='O')
                grid[i][j]='X';
            }
        } 
    }
*/
//Number of Distinct Islands
/*
void dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>>& vis, int drow[], int dcol[],vector<pair<int,int>> &v,int base_row,int base_col)
    {
        vis[row][col]=1;
        v.push_back({row-base_row,col-base_col});
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol] == 1)
            dfs(nrow,ncol,grid,vis,drow,dcol,v,base_row,base_col);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>>st;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,vis,drow,dcol,v,i,j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }   
*/
int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;  
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
