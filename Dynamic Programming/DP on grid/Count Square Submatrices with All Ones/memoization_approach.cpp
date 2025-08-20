#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(n*m + n*m)

// Approach :-   
// For finding the total count of squares we need to count the contribution of each row & col 
// A square is formed when left, up, upLeft are all 1 
// for counting ways we have to check the min number of square form at these 3 size + 1(for current value)
// if the value of matrix is 0 then no square can me formed 
// base case will be whenever row and col becomes -ve, we've reutrn 0 stating no squre possible 


//link :- https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
private:
    int n, m;
    vector<vector<int>> dp;

    int solve(int row, int col, vector<vector<int>> &matrix){
        if(row < 0 || col < 0)      return 0;
        if(dp[row][col] != -1)      return dp[row][col];
        if(matrix[row][col] == 0)   return dp[row][col] = 0;

        int top    = solve(row - 1, col, matrix);
        int left   = solve(row, col - 1, matrix);
        int topleft= solve(row - 1, col - 1, matrix);

        return dp[row][col] = 1 + min({top, left, topleft});
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int> (n, -1));

        int sum = 0;

        for(int row=0; row<m; ++row){
            for(int col=0; col<n; ++col){
                sum += solve(row, col, matrix);
            }
        }
        return sum;
    }
};