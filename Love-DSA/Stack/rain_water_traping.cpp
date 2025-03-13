#include<bits/stdc++.h>
using namespace std;
//Rain water trapping 
/*
here input array dentos the building height and we have to find area which will filled with the water of rain
i/p : 3 0 0 2 0 4 . o/p : 10
-> Total unit of water= submition of(water on each bulding)
-> here we can not use NGE concept beacause here we want . max element in right and max element in left.and we select minimum(maxleft,maxright) and minus arr[i]. now we got our water array now return sum of water array.
*/
/*
2D vector row and column
cout << "Row's Length: " << arr.size();
cout<< "Column's Length: "<< arr[0].size();
*/

int main() 
{
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int maxleft[n];
        int maxright[n];
        int water[n];
        maxleft[0]=arr[0];
        for(int i=1;i<n;i++)    
        {
            maxleft[i]=max(maxleft[i-1],arr[i]);
        }
        maxright[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxright[i]=max(maxright[i+1],arr[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            water[i]=min(maxleft[i],maxright[i])-arr[i];
            sum+=water[i];
        }
        cout<<sum;
    return 0;
}