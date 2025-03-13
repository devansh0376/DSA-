#include<bits/stdc++.h>
using namespace std;
/*
Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:3
Explanation:
The length of the smallest transformation sequence from "der" to "dfs" is 3 i,e "der" -> "dfr" -> "dfs".
*/
 //here we try to convert startword all charecter to a to z and check if the word is exist in wordlist
//so we push in queue with level 
int main() {
    int n;cin>>n;
    vector<string>wordList;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        wordList.push_back(s);
    }
    string startWord,targetWord;cin>>startWord>>targetWord;
    /*
    ->here we change every char of start word's and check that it exist or not in vector
    ->der>aer>ber>cer>der(exist)  step=1
    ->der>dar>abr>dcr>ddr>der(it exist but it visited)>dfr(exist) step=2
    ->dfr>dfa>dfb>dfc>dfd>....>dfs(it exist and it's out target word)  step=3
    */
    queue<pair<string,int>> q;
    unordered_set<string> st(wordList.begin(),wordList.end());
    q.push({startWord,1});
    st.erase(startWord);
    //simple dfs
    while(q.size()>0)
    {
        string word=q.front().first;
        int step=q.front().second;
        q.pop();
        if(word==targetWord)
        return step;
        //now we change all charecter of word one by one check if the word is exist in wordlist
        for(int i=0;i<startWord.size();i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({word,step+1});
                }
            }
            word[i]=original;
        }
    }
    return 0;
 return 0;
}