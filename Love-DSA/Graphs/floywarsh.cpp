#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void shortest_distance(vector<vector<int>>&grid){
	int n=grid.size();
	// Code here
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(grid[i][j]==-1)
			grid[i][j]=1e4;
		}
	}
	for(int via=0;via<n;via++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				grid[i][j]=min(grid[i][j],grid[i][via]+grid[via][j]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(grid[i][j]==1e4)
			grid[i][j]=-1;
		}
	}
}
int main() {
 return 0;
}