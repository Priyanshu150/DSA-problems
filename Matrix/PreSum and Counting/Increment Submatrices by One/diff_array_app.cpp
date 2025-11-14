#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(q*n + n*n)               
// Space complexity :- O(n*n)          

// Approach :-
// maintain a prefix sum / diff array technique for every 1d array in 2d grid 
// update the query in O(n) time and find the answer using prefix sum technique


// Links :- https://leetcode.com/problems/increment-submatrices-by-one/

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // declare a 2d matrix 
        vector<vector<int>> grid(n, vector<int> (n, 0));

        for(auto q: queries){
            int row1 = q[0], col1 = q[1];
            int row2 = q[2], col2 = q[3];

            for(int row = row1; row<=row2; ++row){
                // add contribution
                grid[row][col1] += 1;
                // remove contribtion
                if(col2 + 1 < n)
                    grid[row][col2 + 1] -= 1;
            }
        }

        for(int row=0; row<n; ++row){
            int sum = 0;
            for(int col=0; col<n; ++col){
                sum += grid[row][col];
                grid[row][col] = sum;
            }
        }
        return grid;
    }
};