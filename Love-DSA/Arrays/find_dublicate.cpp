#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
//given array of n+1 interger that have value between 1 to n. there are atleast one number is reapeted.find that number
/*
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/
/*
->whenever they say number are between 1 to n and find dublicate. so all array intger are valid index.use number as index
->so here we use slow fast pointer technique recall linklist question : detect cycle and find start node of cycle 
-> fast move twice of slow , whenever there are slow==fast then there is cycle , now we make one pointer to start of array. move that pointer and slow/head with one when ever they are equal that number is occure twice or more
*/
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int slow=0,fast=0;
    slow=arr[slow];
    fast=arr[arr[fast]];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[arr[fast]];
    } 
    //detect cycle 
    slow=0;
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    cout<<slow<<endl;
    /*
    //by modify the array numbers
    int ans;
    for(int i=0;i<n;i++)
    {
        int idx=abs(arr[i]);
        if(arr[idx]<0)
        {
            ans=arr[i];
            break;
        }
        arr[idx]*=-1;
    }
    cout<<ans;
    */
 return 0;
}

// find all dublicate 
//whenever they said that array number are between in 1 to n use number as index.here number are 1 to n so nth index doesn't exist so we use idx=nums[i]-1;
/*
Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int> v;
    int ans;
    for(int i=0;i<n;i++)
    {
        int idx=abs(arr[i])-1;
        if(arr[idx]<0)
        {
            v.push_back(abs(arr[i]));
        }
        arr[idx]*=-1;
    }
    for(auto i:v)
    cout<<i<<" ";
 return 0;
}
