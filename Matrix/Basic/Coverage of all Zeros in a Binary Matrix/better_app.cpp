#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n*m)
// Space complexity :- O(n*m)

// Approach :-   
// for every row and column store the first and last occurence of one in that 
// then for every 0, find how many out 4 gives it valid coverage  


//Link :- https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1

class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> rowFirstOne(n, -1), rowLastOne(n, -1);
        
        // update the first and last index of 1 in each row
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(mat[row][col] == 1){
                    if(rowFirstOne[row] == -1){
                        rowFirstOne[row] = col;
                    }
                    
                    rowLastOne[row] = col;
                }
            }
        }
        
        vector<int> colFirstOne(m, -1), colLastOne(m, -1);
        
        // update the first and last index of 1 in each col
        for(int col=0; col<m; ++col){
            for(int row=0; row<n; ++row){
                if(mat[row][col] == 1){
                    if(colFirstOne[col] == -1){
                        colFirstOne[col] = row;
                    }
                    colLastOne[col] = row;
                }
            }
        }
        int res = 0;
        
        // traverse on each cell
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                // check if it's 0
                if(mat[row][col] == 0){
                    // check if the is 1 on left side 
                    if(rowFirstOne[row] != -1 && rowFirstOne[row] < col){
                        res += 1;
                    }
                    // check if the is 1 on right side 
                    if(rowLastOne[row] != -1 && col < rowLastOne[row]){
                        res += 1;
                    }
                    // check if the is 1 on up  
                    if(colFirstOne[col] != -1 && colFirstOne[col] < row){
                        res += 1;
                    }
                    // check if the is 1 on down side 
                    if(colLastOne[col] != -1 && row < colLastOne[col]){
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};