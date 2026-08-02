#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n*m)
// Space complexity :- O(n*m)

// Approach :-   
// Store the multiple and factor information for every number already 
// precompute the value for len=1 for every number 
// apply the same concept which we used in memoization to calucate the total number of ways 

// Link :- https://www.geeksforgeeks.org/problems/count-in-array2138/1

class Solution {
  public:
    int count(int n, int m) {
        // dp[len][val]
        // number of arrays of length len ending with val
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        // base case: 
        // Array of length 1 
        for(int val=1; val<=m; ++val){
            dp[1][val] = 1;
        }
        
        // factor[x] -> all factors of x 
        // multiples[x] -> all multiple of x 
        vector<vector<int>> factors(m+1);
        vector<vector<int>> multiples(m+1);
        
        // precompute factors and multiple 
        for(int i=1; i<=m; ++i){
            for(int j=i; j<=m; j+=i){
                factors[j].push_back(i);
                
                // avoid duplicate insertion 
                if(j != i){
                    multiples[i].push_back(j);
                }
            }
        }
        
        // build dp table 
        for(int len=2; len<=n; ++len){
            for(int curr=1; curr<=m; ++curr){
                // add all factors 
                for(int prev: factors[curr]){
                    dp[len][curr] += dp[len-1][prev];
                }
                
                // add all multiple 
                for(int prev: multiples[curr]){
                    dp[len][curr] += dp[len-1][prev];
                }
            }
        }
        
        int ans = 0;        // final answer 
        
        for(int val=1; val<=m; ++val){
            ans += dp[n][val];
        }
        return ans;
    }
};