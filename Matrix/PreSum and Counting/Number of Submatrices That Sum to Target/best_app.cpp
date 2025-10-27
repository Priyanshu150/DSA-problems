#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n*m)
// Space complexity :- O(n)              

// Approach :- 
// using the same concept from the optimized approach 
// instead of using two for loop for row we can use 
// finding subarray sum equal to target k in 1-d array concept 
// since it's a accumulative sum means every current column index represents the sum 
// from starting col to current col, hence this logic can be applied 

// Links :- https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

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
        for(int col1=0; col1<m; ++col1){
            for(int col2=col1; col2<m; ++col2){
                // use subarray sum equal to target k logic of 1-d array 
                int sum = 0;
                unordered_map<int,int> mp;
                mp[sum] += 1;
            
                for(int row=0; row<n; ++row){
                    // find the actual sum 
                    sum += prefixSumMat[row][col2] - (col1 > 0 ? prefixSumMat[row][col1-1] : 0);
                    if(mp.count(sum - target)){
                        res += mp[sum - target];
                    }
                    mp[sum] += 1;
                }
            }
        }
        return res;
    }
};

