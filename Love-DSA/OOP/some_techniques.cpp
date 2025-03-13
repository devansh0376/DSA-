//3. Longest Substring Without Repeating Characters
/*
//j-i+1==m.size() => all char in window is unique
//j-i+1>m.size() => some dublicate char present in window 
-> how i will deside which technique will apply?
here we have to find longest substring with unique char , we can find this using generate 
all substring but this will not work bcoz Constraints are big,here we can use max n*(log(n)) approch
here we have find longest window since window size is not given but condition is given that
window should contain all unique char,so it is a variation of varible size SW pattern.
*/ 
/*
->For apply SW we should know when to increse our window size and when to decrese and 
how we will calculate our ans 
->here when m.size()<j-i+1< so some dublicate char are present then we decrese window
otherwise we increse window.
->just maximize window size for every itteration and return it 
*/
//For convert string number to integer number
/*
42 =>  we can use reverse loop and multple pow(10,i) to the number where i=0 to n-1 
EX : 2*pow(10,0) + 4*pow(10,1) = 2 + 40 = 42 
optimize version 
just travers from begin and do 
ans=ans*10+(s[i]-'0');  EX : (0*10+4)=4 , (4*10+2)=42
i++;
*/

//backtraking technique
/*
->all {possible,combination,permutation,subsets} =>backtracking question     
-make tree diagram 
->template : 
    do something
    explore
    reverse step 1 and further explore
    temp.push_back('('); // do 
    solve(temp,n,ans); // explore
    temp.pop_back(); // revert and explore
    temp.push_back(')'); //do
    solve(temp,n,ans); //explore
->whenever they ask for no dublicate in backtracking question so just sort the array and
 put condtion: i!idx && a[i]==a[i-1] then continue
->here the code of find unique subset
void solve(vector<int>& nums,int idx,vector<vector<int>> & ans,vector<int> v)
{
    ans.push_back(v);
    for(int i=idx;i<nums.size();i++)
    {
        if(i!=idx && nums[i]==nums[i-1])
        continue;
        v.push_back(nums[i]);
        solve(nums,i+1,ans,v);
        v.pop_back();
    }
}
*/

//catlan number
/*
//this problem base on caltan number
Cn = C0*Cn-1 + C1*Cn-2 + C2*Cn-3 + . . . + Cn-1*C0 
Unique Binary Search Trees
int solve(int n)
{
    if(n<=1)return 1;
    int temp=0;
    for(int i=1;i<=n;i++)
    temp+=solve(i-1)*solve(n-i);
    return temp;
}
*/
//subarray count problems or find max/min length subarray with given condition
/*
-> y+z=x => x is the sum of array till ith index 
consider z as ans. and find remaining values exists in map
whenever count do : ans+=m[rem]
*/

//this is pattern type of que. how to indentify this ?
/* 
-ask about number or word 
-each digit or char can be changed 
-you have to reach a target in minimum moves 
-list of number/word are denied or allowed
->here we have to do BFS to reach target in minimum moves 
-level vise add all posible combination and return step when ans==target 
*/

/*
->whenever we use erase function in ser/multiset it will erase all elements 
->if we use iterator of element it will erase only that one element 
int ele=*st.begin();
st.erase(st.begin());
*/

//dijoint set unioun concept
/*
->when to apply ? 
 -whenever they ask about to delete edges/ redudant edges / min edges to connect all node  , you must try with this concept
 -it is very simple same code of find and Union funtion 
 -min edges to connect n node is (n-1) so whenever we do union we minus from (n-1) at the end we get the number of redandatn edges
*/

/*
in any array or string how many times an element occur in all subarray / substring
1 2 3 => 2 appear 4 times but how to know it in 0(1) time 2th index is i=1,n=3 , 
-> left=(i+1),right=(n-i) => ans=left*right
1       2     3
1 2     2 3
1 2 3
*/

//We can find the sum of all subarray in incresion order or in decresion order by heap 
/*
EX : 1 2 3
-First we push all elemnet with idx => {1,0} {2,1} {3,2}
then we extract top element and 
int x=pq.top().first;
int idx=pq.top().second;
pq.push({x+arr[idx+1],idx+1}); thid do {1+2,0} for every {2+3,2} , {1+2+3,2}
*/