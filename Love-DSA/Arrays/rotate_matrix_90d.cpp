#include<bits/stdc++.h>
using namespace std;
/*
Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
i/p:1 2 3  o/p: 7 4 1
    4 5 6       8 5 2  
    7 8 9       9 6 3
*/
int main() {
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // aprroch 1 : we make another matrix and put the element at its right possition.first row become last column
    /*
    i j  i j (j become i and i=n-i-1)
    0 0->0 2  1 0->0 1  2 0->0 2
    0 1->1 2  1 1->1 1  2 1->1 2
    0 2->2 2  1 2->2 1  2 2->2 2
    */
   /*
    int temp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[j][n-i-1]=matrix[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j]=temp[i][j];
        }
    }
    */
    // approch 2 : take transpose and reverse every row(swap column)
    /*
      A       AT     revrse rows
    1 2 3   1 4 7   7 4 1
    4 5 6 ->2 5 8 ->8 5 2   
    7 8 9   3 6 9   9 6 3
    -> for take transpose of the matrix.. digonal element will be at same place and other element is change i=j and j=i
    */
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
 return 0;
}