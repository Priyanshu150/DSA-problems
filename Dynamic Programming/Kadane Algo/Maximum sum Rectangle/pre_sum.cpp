#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2 * m^2)
// Space Complexity: O(n)

// Approach :- 
// we'll use the prefix sum technique in this problem 
// maintain a prefix sum matrix with sum row-wise 
// i.e. curr_col value will represent the sum of col value from starting to this index
// Fix the row1, col1, col2 and traverse using row2 to find the sum of every matrix 
// maintain the max sum from all the matrix


// Link :- https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<vector<int>> prefixSumMat(n, vector<int> (m, 0));

        // sum calculate row-wise 
        for(int row=0; row<n; ++row){
            int sum = 0;
            for(int col=0; col<m; ++col){
                sum += matrix[row][col];
                prefixSumMat[row][col] = sum;
            }
        }
        // finding all the sum of sub-matrix using pre-sum technique
        for(int row1=0; row1<n; ++row1){
            for(int col1=0; col1<m; ++col1){
                for(int col2=col1; col2<m; ++col2){
                    int sum = 0;
                    for(int row2=row1; row2<n; ++row2){
                        sum += prefixSumMat[row2][col2] - (col1 > 0 ? prefixSumMat[row2][col1-1] : 0);
                        res = max(res, sum);
                    }
                }
            }
        }
        return res;
    }
};