#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(row*row)
// Space complexity :- O(row)

// Approach :-   
// optimize the space to 1d array based on tabulation approach 

// Link :- https://leetcode.com/problems/champagne-tower/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // intitalize 1d dp with a default value of 0
        vector<double> curr(query_row+1, 0.0);

        // top of the tower case 
        curr[0] = (double)poured;

        for(int row=0; row<query_row; ++row){
            // i
            vector<double> ahead(query_row+1, 0.0);

            for(int col=0; col<=row; ++col){
                // extra that has to be given to other glasses 
                double extra = (curr[col] - 1.0) / 2.0;

                if(extra > 0){
                    // add the contribution to down and down-right glass
                    ahead[col] += extra;
                    ahead[col+1] += extra;
                }
            }
            // update the previous row 
            curr = ahead;
        }
        return min(1.0, curr[query_glass]);
    }
};