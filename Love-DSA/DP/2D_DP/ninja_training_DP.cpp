#include<bits/stdc++.h>
using namespace std;
//ninza training or geek's traininig
/*
1 col : running, 2nd col : fighting , 3rd col : practice
i/p: 2 1 3 , o/p:25
     3 4 6 
     10 1 6
     8 3 7
->we can do task that we didn't done just previous.w
*/

// =>recurence : solve(day,last) then write base case 
int solve1(int day,int last,vector<vector<int>>& arr,vector<vector<int>>& v)
{
    int mx=0;
    if(day==0)
    {
        for(int task=0;task<3;task++)
        {
            if(task!=last)
            mx=max(mx,arr[0][task]);
        }
        return mx;
    }
    if(v[day][last]!=-1)
    return v[day][last];
    
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=arr[day][task]+solve1(day-1,task,arr,v);
            maxi=max(maxi,point);
        }
    }
    return v[day][last]=maxi;
}
  int solve2(int day,int last,vector<vector<int>>& arr)
  {
      int n=arr.size();
      int dp[n][4];
      dp[0][0]=max(arr[0][1],arr[0][2]);
      dp[0][1]=max(arr[0][2],arr[0][0]);
      dp[0][2]=max(arr[0][1],arr[0][0]);
      dp[0][3]=max(arr[0][1],max(arr[0][0],arr[0][2]) );
      
      for(int day=1;day<n;day++)
      {
         for(int last=0;last<4;last++)
         {
             dp[day][last]=0;
             for(int task=0;task<3;task++)
             {
                 if(task!=last)
                 {
                     int point=arr[day][task]+dp[day-1][task];
                     dp[day][last]=max(dp[day][last],point);
                 }
             }
         }
      }
      return dp[n-1][3];
  }
int main() {
    int n;cin>>n;
    vector<vector<int>>arr;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<3;j++)
        {
            int x;cin>>x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    vector<vector<int>>v(n,vector<int>(4,-1) );
    //int ans1=solve1(n-1,3,arr,v);
    //cout<<ans1<<endl;
    int ans2=solve2(n-1,3,arr);
    cout<<ans2<<endl;
 return 0;
}