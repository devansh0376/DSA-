/*
->now we do some greedy problems.Think greedly.
How to identify : In the question they ask to find min/max.and constrain given like 10^9.
How to solve : in most of greedy problems first apply sorting then make some moves base on greedy.
*/
//activity selection problem
/*
->we have activity array(two array start time and end time array) of job time.
->we want to do maximum job.but we can't do two job at one time.one time one job
Input : N = 4
          a1  a2  a3  a4
start[] ={ 1, 3 , 2 , 5 } -> we can do max three activity : a1(1,2),a2(3,4) and a4(5,6)
end[] =  { 2, 4 , 3 , 6 }
output : 3 
*/
/*
->for this problem we think greedy: if we want do maximum job so do which end fast.so we sort activiy WTR to their end time.and now we take activity which no overlap.
->next activiy's start time > current activiy's end time ->so we can do this job.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;
    int start[n],end[n];
    for(auto &i:start)cin>>i;
    for(auto &i:end)cin>>i;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    v.push_back({start[i],end[i]});
    //step 1: sort activity WRT end time
    auto cmp=[](pair<int,int>a,pair<int,int>b){return a.second<b.second; };
    sort(v.begin(),v.end(),cmp);
    int mx=1;
    int end_time=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>end_time)
        {
            mx++;
            end_time=v[i].second;
        }
    }
    cout<<mx<<endl;
 return 0;
}