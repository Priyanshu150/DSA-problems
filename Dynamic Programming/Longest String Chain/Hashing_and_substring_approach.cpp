#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(N), N*sz*log(N) )  
// Space complexity :- O(N)

// Approach :-
// sort the array in increasing order based on the size of the array
// use a map to keep track of maximum string chain till that string 
// For every string try to remove every char and find the wheather that removed_char_string exist 
// if that exist then the new_length will be 1 + length_chain_till_removed_char_string
// save the state in dp and maitain max length in a variable 

// Link :- https://www.geeksforgeeks.org/problems/longest-string-chain/1

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [](string &s1, string &s2){
            return s1.size() < s2.size();
        });
        unordered_map<string,int> dp;
        int longest = 1;
        
        for(string &word: words){
            dp[word] = 1;
            for(int i=0; i<word.size(); ++i){
                string predecessor = word.substr(0, i) + word.substr(i+1);
                
                if(dp.find(predecessor) != dp.end())
                    dp[word] = dp[predecessor]+1;
            } 
            longest = max(longest, dp[word]);
        }
        return longest;
    }
};
