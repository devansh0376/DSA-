#include <bits/stdc++.h>
using namespace std;
/*
Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
i/p: 1 1 1 o/p: 1 0 1
     1 0 1      0 0 0
     1 1 1      1 0 1
*/
int main()
{
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
    // approch 1 make two row and column array and do 1 whene arr[i][j]==0 and update in original array when
    // row[i]=1 or col[j]=1  TC=0(n*n) SC=0(n+m)
    /*
    int row[n]={0};
    int col[m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i]||col[j])
            matrix[i][j]=0;
        }
    }
    */
    // no extra space TC=0(n*n) SC=0(1)
    /*
     we do same process but on same matrix:
     1 1 1 1
     1 0 1 1
     1 1 0 1
     0 1 1 1
    */
    int col0=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    // solve matrix avoiding fisrt row and first column
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
    // first solve for first column then first row
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}