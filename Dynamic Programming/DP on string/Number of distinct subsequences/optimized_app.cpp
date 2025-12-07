#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-   
// for creating every subsequence possible subsequence we'll use take or not take case 
// following the same principle there will 2*prev_sub-sequence_count for curr_subsequence_count
// if we remove the duplicate that will be our answer 
// every time a char is repeated that mean that many number of sub-sequence will be repeated 
// so we'll prune the branch directly i.e. we'll subtract that sub-sequence from current count 
// we'll update the index of each occuring in an array 
// dp[freq[s[i] - 'a']] will represent how many string generated previously using repating s[i]

//Link :- https://www.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

class Solution {
  public:
    int distinctSubseq(string &str) {
        int n = str.size(), mod = 1e9+7;
        vector<int> dp(n+1, 0), freq(26, -1);
        // base case 
        dp[0] = 1;
        
        for(int i=0; i<n; ++i){
            // 2 time of previous value due to take or not take value 
            dp[i+1] = (2*dp[i]) % mod;
            // if the char is repeating then substract duplicate ones 
            if(freq[str[i] - 'a'] != -1) 
                dp[i+1] = (dp[i+1] - dp[freq[str[i] - 'a']] + mod) % mod;
            
            // update the index of current char 
            freq[str[i] - 'a'] = i;
        }
        return dp[n];
    }
};