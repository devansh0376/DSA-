#include<bits/stdc++.h>
using namespace std;
/*
 Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
 Input Format: arr[] = [1,0,-1,0,-2,2], target = 0
Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Explanation: We have to find unique quadruplets from the array such that the sum of those elements is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.
*/
vector<vector<int>> solve1(int nums[],int n,int target)
{
       set<vector<int>>st;
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               set<long long>s;
               for(int k=j+1;k<n;k++)
               {
                   long long sum=nums[i]+nums[j];
                   sum+=nums[k];
                   long long f=target-sum;
                   if(s.find(f)!=s.end())
                   {
                       vector<int>t;
                       t={nums[i],nums[j],nums[k],(int)(f)};
                       sort(t.begin(),t.end());
                       st.insert(t);
                   }
                   s.insert(nums[k]);
               }
           }
       }
       vector<vector<int>>ans (st.begin(),st.end());
       return ans;
}
int c=0;
vector<vector<int>> solve2(int arr[],int n,int k)
{
    sort(arr,arr+n);
    
    vector<vector<int>>ans;

    for(int i=0;i<n;i++)
    {
        if(i>0 && arr[i]==arr[i-1])continue;
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && arr[j]==arr[j-1])continue; 
            int l=j+1,h=n-1;
            while(l<h)  
            {
                long long sum=arr[i]+arr[j]+arr[l]+arr[h];
                if(sum==k)
                {
                    c++;
                    vector<int>t={arr[i],arr[j],arr[l],arr[h]};
                    ans.push_back(t);
                    while(l<h && arr[l]==arr[l+1])l++;
                    while(l<h && arr[h]==arr[h-1])h--;  
                    l++;h--;
                }
                else if(sum<k)
                l++;
                else
                h--;
            } 
        }
    }
    return ans;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<vector<int>> ans=solve2(arr,n,k);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<c;
 return 0;
}