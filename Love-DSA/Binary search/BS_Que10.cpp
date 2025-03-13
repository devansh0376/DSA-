#include<bits/stdc++.h>
using namespace std;
// search in row wise and column wise in sorted array or search in the matrix 
/*
i/p: arr[][]= 10 20 30 40  } row =i,column=j
              15 25 35 45  } row : (i>=0 && i<=n)
              27 29 37 48  } column : (j>=0 && j<=m)
              32 33 39 50  }
     key=29
o/p :3 2
*/
/*
->we start from the arr[m-1] .
-> if ele>arr[m-1] we go to down : i++ else ele<arr[m-1] we go to left : j--
*/
int main() {
    int n,m,k;cin>>n>>m>>k;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int i=0,j=m-1;
    vector<int>v;
    while(i>=0 && i<=n && j>=0 && j<=m)
    {
        if(arr[i][j]==k)
        {
            v.push_back(i);
            v.push_back(j);
            break;
        }
        else if(k>arr[i][j])
        i++;
        else 
        j--;
    }
    for(auto i:v)cout<<i<<" ";
 return 0;
}