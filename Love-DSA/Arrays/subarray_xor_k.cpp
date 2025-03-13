#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    unordered_map<int,int> m;
    m[0]=1;
    int xr=0,ans=0;
    /*
    y^z=xr
    y^k=xr : assume that xor of elments z=k
    y^k^k=xr^k
    y=xr^k so if y exist previous so there exist subarray which has xor=k 
    */ 
    for(int i=0;i<n;i++)
    {
        xr^=arr[i];
        int rem=xr^k;
        if(m.find(rem)!=m.end())
        ans+=m[rem];
        
        m[xr]++;
    }
    cout<<ans<<endl;
 return 0;
}   