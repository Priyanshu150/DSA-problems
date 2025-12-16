#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n^2 * 2^n)
//Space complexity :- O(n* 2^n) 

// Approach :-
// In-order to save recursion stack space we use tabulation approach 
// dp[1][0] = 0, base case i.e. for 0th node as we start from it 
// traverse on all the bitmask and for every node check where all other list of nodes we can traverse 
// dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j])

//link :- https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1

class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if(n == 1)      return cost[0][0];
        
        // maximum cost to visit all cities 
        const int INF = INT_MAX;
        int full = 1<<n, fullMask = full-1;
        
        // dp[mask][i] represents the minimum cost to visit all cities 
        // corresponding to the set bits in 'mask', ending at city 'i'
        vector<vector<int>> dp(full, vector<int> (n, INF));
        dp[1][0] = 0;
        
        // iterate over all subsets of cities 
        for(int mask=1; mask<full; mask++){
            for(int i=0; i<n; ++i){
                // skip if city i is not included in mask
                if(!(mask & (1<<i)))    continue;
                if(dp[mask][i] == INF)  continue;
                
                // try to go to every unvisited city j
                for(int j=0; j<n; ++j){
                    // skip if city j is already visited 
                    if(mask & (1<<j))   continue;
                    
                    int nxt = mask | (1 << j);
                    dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
        int ans = INF;
        for(int i=0; i<n; ++i){
            // if last city on path is i and cost of path is infinity 
            if(dp[fullMask][i] != INF){
                ans = min(ans, dp[fullMask][i] + cost[i][0]);
            }
        }
        return ans;
    }
};