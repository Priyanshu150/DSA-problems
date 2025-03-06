#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)
// Space complexity :- O(1)

// Approach :-
// We can use same grid to mark the same wheather a number is present or not 
// Every index in the grid represent a number if a number exist then mark by multiplying -1
// We traverse on every element of grid and then calulate the row and col of that number by taking absolute value
// row will be (val-1)/n and col will be (val-1)%n for 1-based index
// If we find any index already as -ve that means it's a repeating number
// Again we'll traverse in the array and the i,j which is not negative that number of index is missing
// using i,j we can calculate the number as i*n + j+1

// Link :- https://leetcode.com/problems/find-missing-and-repeated-values/description/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(2, 0);
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int val = abs(grid[i][j]);
                int row = (val-1)/n, col = (val-1)%n;

                if(grid[row][col] < 0) 
                    res[0] = val;
                else 
                    grid[row][col] *= -1;
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] > 0)
                    res[1] = (i*n) + j+1;
                else
                    grid[i][j] *= -1;
            }
        }
        return res;
    }
};