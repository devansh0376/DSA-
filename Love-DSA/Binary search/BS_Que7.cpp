#include<bits/stdc++.h>
using namespace std;
// minimum differnce in sorted array
/*
i/p : 1 3 8 10 15,k=12 }  1 3 8 10 15 }-> -12 subtract this from main array 
o/p : 10               }  11 9 4 2 3  }-> minimum element is 2 and it's index is 3. so we have to return this 
                       }  element from main array so output  is arr[3]=10
*/
/*
-> if key is present in our array so we get 0 at the key's index and so it is simple binary search
ex : 4 6 2 10 , k=2 after subtrace array: 2 4 0 10 so our ans is at index 2 arr[2], if key present so simple return it's index
-> if key is not present in our array.in Binary search out low and high is point to the closest of our key
we want minimum difference so our aim to is to go as near as our key..
->ans : min(key-l,key-h)
*/
int ans(int arr[],int n,int k)
{
    int l=0,h=n-1;
    int mid=(l+h)/2;
    while(l<h)
    {
        if(arr[mid]==k)
        return mid;
        if(k>arr[mid])
        l=mid+1;
        else 
        h=mid-1;

        mid=(l+h)/2;
    }
    int t=min(abs(k-arr[l]), abs(k-arr[h]));
    return t;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int i=ans(arr,n,k);
    cout<<arr[i];
 return 0;
}