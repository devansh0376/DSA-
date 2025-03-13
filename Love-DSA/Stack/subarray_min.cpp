#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
/*Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.*/
/*
-> link : https://leetcode.com/problems/sum-of-subarray-minimums/solutions/2118729/very-detailed-stack-explanation-o-n-images-comments/
->here we use monotonic stack concept :  keep element in stack such that it is incresing or decrising 
How many subarray start with k minimum element ? ans = k * number of subarray with k min element 
ex : 3 1 2 4
3,{3,1},{3,1,2},{3,1,2,4},{1},{1,2},{1,2,4},{2},{2,4},{4} -> min 3,1,1,1,1,1,1,2,2,4 => 3*1 + 1*6 + 2*2 + 4*1 = 17
->recall the stock span problem in that problem we have to store the distance of the element which is smaller than current element.Ahiya aapde koi element k ketli length na subarray ma minimum rehse elte aapde tya sudhi subarray rakhvano jya sudhi current element karta koi big element occur na thay. But jo start ma j small element occur thai gayo to tya 1 rehse.
-> here the same proble but in diiferent way. here we should stop when big element occure. like how many big we have to store NSE left and NSE right 

 index        0 1 2 3  
              3 1 2 4
NSE to Right  1 3 2 1 (right ma jo koi element na male to n) value = NSER's index  - current'index
NSE to Left   1 2 1 1 (left ma jo koi element na male to -1) value = current'index - NSEL's index
ans :         3 6 4 4 (NSER*NSEL*arr[i])
 
*/
vector<int> NSER(int arr[],int n)
{
    vector<int> v;
    stack<pair<int,int>>s;
    for(int i=n-1;i>=0;i--)
    {
        while(s.size()>0 && (s.top().first)>=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(n);
        else 
        v.push_back((s.top().second));

        s.push({arr[i],i});
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        v[i]=v[i]-i;
    }
    return v;
}
vector<int> NSEL(int arr[],int n)
{
    vector<int> v;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        while(s.size()>0 && (s.top().first)>=arr[i])
        s.pop();
        if(s.size()==0)
        v.push_back(-1);
        else 
        v.push_back((s.top().second));

        s.push({arr[i],i});
    }
    for(int i=0;i<n;i++)
    {
        v[i]=i-v[i];
    }
    return v;
}
//second method
/*
->we make two array left and right intialy filled with 1. they represent the for current element how many element continues greater than current element.
->we make two stack for left and right.if element > s.top() -> we pop element else we add to our cnt variable and assign this cnt varible to left/right array
*/
int solve(int arr[],int n)
{
    vector<int> left(n,1),right(n,1);
    // for fill left array 
    stack<pair<int,int>>sl,sr;
    for(int i=0;i<n;i++)
    {
        int cnt=1;
        while(sl.size()>0 && (sl.top().first)>=arr[i])//here we make monotonic incresing stack
        {
            cnt+=sl.top().second;
            sl.pop();
        }
        sl.push({arr[i],cnt});
        left[i]=cnt;
    }
    for(int i=n-1;i>=0;i--)
    {
        int cnt=1;
        while(sr.size()>0 && (sr.top().first)>=arr[i])//here we make monotonic incresing stack
        {
            cnt+=sr.top().second;
            sr.pop();
        }
        sr.push({arr[i],cnt});
        right[i]=cnt;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=arr[i]*left[i]*right[i];
    }
    return ans;
}
int main() {
    int n;cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<int> v1=NSER(arr,n);
    vector<int> v2=NSEL(arr,n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=arr[i]*v1[i]*v2[i];
    }
    int ans1=solve(arr,n);
    cout<<ans1<<endl;
    cout<<ans<<endl;
 return 0;
}