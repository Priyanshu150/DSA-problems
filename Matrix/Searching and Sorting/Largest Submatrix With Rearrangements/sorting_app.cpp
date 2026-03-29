#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m*log(m))
// Space complexity :- O(2*m)

// Approach :- 
// since we can swap any col and it's will not costing us anything then we can swap any column with anyone 
// so we'll maintain the heights at every row level and sort the heights in descending order 
// i.e. higher height will come first and moving from left to right the base of rectangle will also increase
// the area will be height * base, we'll maintain the maximum height with that

// Links :- https://leetcode.com/problems/largest-submatrix-with-rearrangements/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<int> prevRow(m, 0);

        for(int row=0; row<n; ++row){
            vector<int> currRow(m, 0);

            for(int col=0; col<m; ++col){
                // grid value is 1 
                if(matrix[row][col] == 1){
                    // update the height based on the previous height
                    currRow[col] = 1 + prevRow[col];
                }
            }
            // sort the array based on the height 
            vector<int> temp = currRow;
            sort(temp.begin(), temp.end(), greater<int> ());

            for(int i=0; i<m; ++i){
                // find the height and base of rectangle 
                int height = temp[i];
                int base = (i+1);
                // update the max area 
                res = max(res, height * base);
            }
            prevRow = currRow;
        }
        return res;
    }
};