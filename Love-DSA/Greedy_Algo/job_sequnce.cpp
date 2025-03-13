#include<bits/stdc++.h>
using namespace std;
/*
Given an array of jobs with deadline and profit.we can earn the profit money.maximixe the profit if only one jon can be scheduled at a time.
jobs : dealine:4  1  1  1 
       profit :20 10 40 30
we should do : job 3 and job 1 ->profit =40+20=60
->approch : we sort the array based on profit:
1  1  4  1  now we check if time<dealine so we take profit and do time++
40 30 20 10
*/
/*
    -ahiya job dedline pehla karvani 6.ex : 3 dedline hoy to te job 3 time pehla thai javi joie 
    -to aapde darek job last time par karisu jethi aagal aapde biji job kari sakie
    -pehla aapde profit na mujab sort karisu decending oreder
    -pa6i aapde ek vector banavisu jema aapde je job thai gai hoy tene mark karisu
*/
struct job
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
int main() {
       int n;cin>>n;
       job arr[n];
       for(int i=0;i<n;i++)
       {
              int x,y,z;
              cin>>x>>y>>z;
              arr[i].id=x;
              arr[i].dead=y;
              arr[i].profit=z;
       }
       auto cmp=[](job a,job b){ return a.profit>b.profit; };
       sort(arr,arr+n,cmp);
       int max_dedline=0;
       for(int i=0;i<n;i++)
       {
       max_dedline=max(max_dedline,arr[i].dead);
       }
       vector<int> mark(max_dedline+1,-1);
       int cnt_job=0,max_profit=0;
       for(int i=0;i<n;i++)
       {
              int job_id=arr[i].id;
              int profit=arr[i].profit;
              int dedline=arr[i].dead;
              for(int j=dedline;j>0;j--)
              {
                     if(mark[j]==-1)
                     {
                     cnt_job++;
                     mark[j]=job_id;
                     max_profit+=profit;
                     break;
                     }
              }
       }
       cout<<cnt_job<<" "<<max_profit<<endl;
 return 0;
}