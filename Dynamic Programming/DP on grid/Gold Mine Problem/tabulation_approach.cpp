#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2)
// Space complexity :- O(n^2)

// Approach :-  
// Intialize the dp grid with 0 denoting the initial state 
// loop col from n-1 to 0 and row from 0 to n-1
// express the same posssibilities of recursion
// at last traverse on the first column and find the maximum answer 


// links :- https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int> (m+1, 0));
        
        for(int col=m-1; col>=0; --col){
            for(int row=0; row<n; ++row){
                    int up = 0, right = 0, down = 0;
                 
                    if(row-1 >= 0)
                        up += dp[row-1][col+1];
                    
                    if(row+1 < n)
                        down += dp[row+1][col+1];
                    
                    right = dp[row][col+1];
                    
                    dp[row][col] = mat[row][col] + max({up, right, down});
            }
        }
        for(int r=0; r<n; ++r){
            res = max(res, dp[r][0]);
        }
        return res;
    }
};