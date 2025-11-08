#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m*k)
// Space complexity :- O(n*m)           

// Approach :- 
// we can further optimize tabulation 3-d dp space to
// 2 2-d dp space, by maintain curr and prev 2-d dp 

// Links :- https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        // use two 2-d dp table 
        vector<vector<int>> prev(m, vector<int> (k+1, 0)), curr;
        
        // base case 
        if(mat[0][0] <= k)
            prev[0][mat[0][0]] = 1;
        
        // explore all the option or row*col*sum
        for(int row=0; row<n; ++row){
            curr = vector<vector<int>>(m, vector<int>(k+1, 0));
            
            for(int col=0; col<m; ++col){
                for(int sum=0; sum<=k; ++sum){
                    if(row == 0 && col == 0){
                        if(mat[0][0] <= k)
                            curr[0][mat[0][0]] = 1;
                            
                        continue;   
                    }
                    
                    int &ans = curr[col][sum];
                    // traverse up of the grid 
                    if(row-1 >= 0 && sum - mat[row][col] >= 0){
                        ans += prev[col][sum - mat[row][col]];
                    }
                    // traverse left of the grid 
                    if(col-1 >= 0 && sum - mat[row][col] >= 0){
                        ans += curr[col-1][sum - mat[row][col]];
                    }
                }
            }
            // change after every row - row level change
            prev = curr;
        }
        return prev[m-1][k];
    }
};