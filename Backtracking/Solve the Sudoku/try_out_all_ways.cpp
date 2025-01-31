#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(9^n)
// Space complexity :- O(1)

// Approach :- 
// Go on every cell of sudoku and try out keep every number one by one 
// If you find a conflicting number return false 
// If you able to fill all the place return true
// Check whether the recurion is returning true for it's sub-problem and return true for that point
// Return type of recursion should be true to check whether sub-problem to know whether it has successded or not 

//Link :- https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

class Solution {
  private:
    bool isSafe(int row, int col, int num, vector<vector<int>> &mat){
        
        for(int i=0; i<9; ++i){
            if(mat[row][i] == num)
                return false;
            
            if(mat[i][col] == num)
                return false;
            
            if(mat[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == num)
                return false;
        }
        return true;
    }
  
    bool solve(vector<vector<int>> &mat){
        
        for(int row=0; row<9; ++row){
            for(int col=0; col<9; ++col){
                if(mat[row][col] == 0){
                    for(int num=1; num<=9; ++num){
                        if(isSafe(row, col, num, mat)){
                            mat[row][col] = num;
                            
                            if(solve(mat))
                                return true;
                            
                            mat[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
  
  public:
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
};