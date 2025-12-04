#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N^3)
// Space complexity :- O(N^2)

// Approach :-   
// Instead multiplying the level with freq, we can remove that state and instead 
// add all the value from i to j as curr_val 
// and later in subtree again which are present got added, hence we don't need to multiply them 
// i.e 1*12 + 2*50 => (12 + 50) for level 1 + (50) for level 2 gives same answer 
// Since 1 parameter decreases, now we can memoize the solution using 2d dp 

//Link :- https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1

class Solution {
  private:
    vector<int> preSum;
    vector<vector<int>> dp;
    
    int solve(int i, int j, vector<int> &keys){
        // base case 
        if(i > j)
            return 0;
            
        // memoize
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = INT_MAX;
        // loop from i to j 
        for(int ind=i; ind<=j; ++ind){
            // find the current node cost using prefix sum 
            int cost = (preSum[j+1]-preSum[i]) + solve(i, ind-1, keys) + solve(ind+1, j, keys);
            // update the min answer 
            res = min(res, cost);
        }
        return dp[i][j] = res;
    }
  
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = freq.size();
        preSum.resize(n+1, 0);
        
        // standard prefix sum technique
        for(int i=0; i<n; ++i){
            // sum eqaul to current freq 
            preSum[i+1] = freq[i];
            // add previous sum 
            if(i > 0)
                preSum[i+1] += preSum[i];
        }
        // intialize 2d dp with -1
        dp = vector<vector<int>> (n, vector<int> (n, -1));
        // call recursion 
        return solve(0, n-1, keys);
    }
};