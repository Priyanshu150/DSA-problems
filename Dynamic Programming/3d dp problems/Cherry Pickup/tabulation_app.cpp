#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*n)  
// Space complexity :- O(n*n*n)

// Approach :-  
// we can further optimize the memoization to tabulation 
// base case will be everything will be initialized to -1e5 and dp[n-1][n-1][n-1] = grid[n-1][n-1]
// r1 = (n-1 to 0), c1 = (n-1 to 0) and c2 = (n-1 to 0)
// express the same possibilities from recusion case 
// at last the answer will max(0, dp[0][0][0])

// Link :- 
// leetcode :- https://leetcode.com/problems/cherry-pickup/description/
// gfg :- https://www.geeksforgeeks.org/problems/chocolate-pickup-ii/1

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1e5)));

        // Base case: both at bottom-right
        dp[n-1][n-1][n-1] = grid[n-1][n-1];

        for(int r1 = n-1; r1 >= 0; --r1) {
            for(int c1 = n-1; c1 >= 0; --c1) {
                for(int c2 = n-1; c2 >= 0; --c2) {
                    int r2 = r1 + c1 - c2;
                    if(r2 < 0 || r2 >= n) continue;
                    if(grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;

                    int cherries = (r1 == r2 && c1 == c2) ? grid[r1][c1] 
                                  : grid[r1][c1] + grid[r2][c2];

                    int best = -1e5;
                    if(c1+1<n && c2+1<n) best = max(best, dp[r1][c1+1][c2+1]);
                    if(c1+1<n)           best = max(best, dp[r1][c1+1][c2]);
                    if(r1+1<n && c2+1<n) best = max(best, dp[r1+1][c1][c2+1]);
                    if(r1+1<n)           best = max(best, dp[r1+1][c1][c2]);

                    if(best > -1e5) 
                        dp[r1][c1][c2] = cherries + best;
                }
            }
        }
        return max(0, dp[0][0][0]);
    }
};