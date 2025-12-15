#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m + q)  
// Space complexity :- O(n*m)

// Approach :-
// we'll find the area or sum till (r, c) and maintain a matrix 
// matrix(r, c) represents sum/area of matrix from (0, 0) to (r, c)
// we'll use to find the our answer in O(1) time 
// for find area, we'll use the formula that area[row][col] = curr_elem + area[row-1][col] + area[row][col-1] - area[row-1][col-1]
// because area[row-1][col-1] was added twice
// using same concept we'll find the area of the grid based on query (r1, c1) & (r2, c2)
// the formula for that will be (area[r2][c2] - area[r1-1][c2] - area[r2][c1-1] + area[r1-1][c1-1])
// add area[r1-1][c1-1] because it'll be subtracted twice 

// Link :- https://www.geeksforgeeks.org/problems/2d-submatrix-sum-queries/1

class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> preSumMat(n+1, vector<int> (m+1, 0));
        
        // find the prefix sum on matrix i.e every (row,col) represent
        // sum of all element from (0, 0) to (row, col)
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                preSumMat[row+1][col+1] = preSumMat[row][col+1] + preSumMat[row+1][col] 
                            - preSumMat[row][col] + mat[row][col];
            }
        }
        vector<int> res;
        
        // for each query 
        for(auto q: queries){
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            // find the sum using area concept 
            int sum = preSumMat[r2+1][c2+1] - preSumMat[r1][c2+1] - preSumMat[r2+1][c1]
                    + preSumMat[r1][c1];
                
            res.push_back(sum);
        }
        return res;
    }
};
