#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(row*row)
// Space complexity :- O(row*row)

// Approach :-   
// replicating the same logic from memoziation we can start from top of the tower 
// keep 1 unit to itself and distribute rest / 2.0 to bottom two glasses 
// i.e. (row+1, col) & (row+1, col+1), until we reach the given (row, col)
// at last return min(1, dp[row][col]) value because at max the value can be 1.0

// Link :- https://leetcode.com/problems/champagne-tower/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // intitalize 2d dp with a default value of 0
        vector<vector<double>> dp(query_row+1, vector<double> (query_row+1, 0.0));

        // top of the tower case 
        dp[0][0] = (double)poured;

        for(int row=0; row<query_row; ++row){
            for(int col=0; col<=row; ++col){
                // extra that has to be given to other glasses 
                double extra = (dp[row][col] - 1.0) / 2.0;

                if(extra > 0){
                    // add the contribution to down and down-right glass
                    dp[row+1][col] += extra;
                    dp[row+1][col+1] += extra;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};