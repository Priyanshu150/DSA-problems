#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)   
//Space complexity :- O(1)

// Approach :-
// keep track of the last and first row occurence in the matrix that will give us length of reactangle
// similar for column will give us breath
// length * breath will be area of rectangle 


//Link :- https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int min_row_ind = n+1, max_row_ind = -1;
        int min_col_ind = m+1, max_col_ind = -1;

        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(grid[row][col]){
                    min_row_ind = min(min_row_ind, row);
                    max_row_ind = max(max_row_ind, row);
                    min_col_ind = min(min_col_ind, col);
                    max_col_ind = max(max_col_ind, col);
                }
            }
        }
        return (max_row_ind - min_row_ind + 1)*(max_col_ind - min_col_ind + 1);
    }
};