#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m)
//Space complexity :- O(n*m)

// Approach :-   
// A square is formed when left, up, upLeft are all 1 
// for counting ways we have to check the min number of square form at these 3 size + 1(for current value)
// if the value of matrix is 0 then no square can me formed 
// first row and col can only have the square of size 1 
// value of dp[row][col] will be min(dp[row-1][col], dp[row-1][col-1], dp[row][col-1]) + 1


//link :- https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));

        // count square of size 1 in first column
        for(int col=0; col<n; ++col){
            dp[0][col] = matrix[0][col];
            if(dp[0][col])
                res++;
        }

        // count square of size 1 in first row 
        for(int row=1; row<m; ++row){
            dp[row][0] = matrix[row][0];
            if(dp[row][0])
                res++;
        }

        for(int row=1; row<m; ++row){
            for(int col=1; col<n; ++col){
                if(matrix[row][col]){
                    int minSize = min({dp[row-1][col-1], dp[row-1][col], dp[row][col-1]});
                    dp[row][col] = 1+minSize;
                    res += dp[row][col];
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), sum = 0;
        vector<vector<int>> dp = matrix;

        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(dp[row][col] == 1 && row>0 && col>0){
                    int minLength = min({dp[row-1][col], dp[row-1][col-1], dp[row][col-1]});
                    dp[row][col] = minLength + 1;
                }
                sum += dp[row][col];
            }
        }
        return sum;
    }
};