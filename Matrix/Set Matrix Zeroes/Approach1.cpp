#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)  
// Space complexity :- O(n + m)

// Approach :- 
// maintain 2 array, one for row and other for col where we mark the value the current row or col is 0
// matrix[row][col] = 0, then mark the row and col as true indicating that is 0
// traverse the matrix again and if row or col is marked as true and put the value as 0

// Link :- https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<bool> row_Containing_Zero(n, false), col_Containing_Zero(m, false);
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(mat[row][col] == 0){
                    row_Containing_Zero[row] = true;
                    col_Containing_Zero[col] = true;
                }
            }
        }
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(row_Containing_Zero[row] || col_Containing_Zero[col])
                    mat[row][col] = 0;
            }
        }
    }
};