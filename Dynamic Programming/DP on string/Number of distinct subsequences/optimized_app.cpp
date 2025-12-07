#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-   
// for creating every subsequence possible subsequence we'll use take or not take case 

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