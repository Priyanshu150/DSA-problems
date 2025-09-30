#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)  
// Space complexity :- O(1)

// Approach :- 
// use the same concept as previous one 
// Instead of using extra space use first row and column to save wheather a row has zero or not 
// But this we can only do for row and col greater than 1 
// otherwise we'll end up getting all the value of matrix as 0
// for tracking first row and col we can keep two separate variables

// Link :- https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size(), row1 = 0, col1 = 0;
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(mat[row][col] == 0){
                    if(row == 0){
                        row1 = 1;
                    }
                    if(col == 0){
                        col1 = 1;
                    }
                    if(row > 0 && col > 0){
                        mat[row][0] = 0;
                        mat[0][col] = 0;
                    }
                }
            }
        }
        for(int row=1; row<n; ++row){
            for(int col=1; col<m; ++col){
                if(mat[row][0] == 0 || mat[0][col] == 0){
                    mat[row][col] = 0;
                }
            }
        }
        if(col1){
            for(int row=0; row<n; ++row){
                mat[row][0] = 0;
            }
        }
        if(row1){
            for(int col=0; col<m; ++col){
                mat[0][col] = 0;
            }
        }
    }
};