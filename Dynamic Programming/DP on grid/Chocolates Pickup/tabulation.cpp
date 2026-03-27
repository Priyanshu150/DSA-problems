#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m*m)
// Space Complexity: O(n*m*m)

// Approach :- 
// express row (0 to n-1), col1 to (m-1 to 0) and col2 to (0 to m-1)
// and conver the memoized solution to tabulation change the sates of dp accordingly 

// Link :- https://www.geeksforgeeks.org/problems/chocolates-pickup/1

class Solution {
  private:
    int n, m;
    
    // check if the two columns are valid or not 
    bool isValid(int col1, int col2){
        return (col1 >= 0 && col1 < m && col2 >= 0 && col2 < m);
    }
  
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (m+1, 0)));
        
        // express all possible ways in term of loops 
        for(int row=n-1; row>=0; --row){
            for(int col1=m-1; col1>=0; --col1){
                for(int col2=0; col2<m; ++col2){
                    
                    int value = 0, &res =  dp[row][col1][col2];
                    
                    // compute chocolate collected by robot depending on the col they are present
                    if(col1 == col2){
                        value = grid[row][col1];        // same col contribution 
                    }
                    else{
                        value = grid[row][col1] + grid[row][col2];      // idifferent col contribution
                    }
                    
                    // try out all ways to move two robots 
                    for(int c1=-1; c1<=1; ++c1){
                        for(int c2=-1; c2<=1; ++c2){
                            // find the next columns value 
                            int ncol1 = col1 + c1;
                            int ncol2 = col2 + c2;
                            
                            // if the columns are valid then 
                            if(isValid(ncol1, ncol2)){
                                int newVal = dp[row+1][ncol1][ncol2];
                                // maintain max value from all ways 
                                res = max(res, newVal + value);
                            }
                        }
                    }
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};