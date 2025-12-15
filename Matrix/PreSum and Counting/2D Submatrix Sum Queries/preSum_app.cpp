#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m + q*m)  
// Space complexity :- O(n*m)

// Approach :-
// use the concept of prefix sum technique 
// find the prefix sum row-wise 
// for each query traverse on column and caluclate the sum of matrix using presum technique 


// Link :- https://www.geeksforgeeks.org/problems/2d-submatrix-sum-queries/1

class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> preSumMat(n, vector<int> (m+1, 0));
        
        // find the prefix sum on matrix column wise 
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                preSumMat[row][col+1] = mat[row][col] + preSumMat[row][col];
            }
        }
        vector<int> res;
        
        for(auto q: queries){
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3], sum = 0;
            
            // traverse on r1 to r2 
            for(int row=r1; row<=r2; ++row){
                // use prefix sum matrix find the sum of each column 
                sum += (preSumMat[row][c2+1] - preSumMat[row][c1]);
            }
            res.push_back(sum);
        }
        return res;
    }
};