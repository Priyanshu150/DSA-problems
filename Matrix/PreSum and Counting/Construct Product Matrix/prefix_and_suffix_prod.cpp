#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// Approach :- 
// intead of finding the product of all element, we'll face the product exceeding problem 
// hence we'll split the product of prefix and suffix product 
// current cell value will be product of prefix and suffix product 


// Link :- https://leetcode.com/problems/construct-product-matrix/description/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long suffix = 1, prefix = 1;
        int n = grid.size(), m = grid[0].size(), mod = 12345;
        
        vector<vector<int>> ans(n, vector<int> (m, 0));     //result matrix 
        
        // stores the suffix product in the matrix 
        for(int row=n-1; row>=0; --row){
            for(int col=m-1; col>=0; --col){
                ans[row][col] = suffix;
                suffix *= grid[row][col];
                suffix %= mod;
            }
        }
        
        // update the prefix product in matrix 
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                ans[row][col] = (prefix * ans[row][col]) % mod;

                prefix *= grid[row][col];
                prefix %= mod;
            }
        }
        return ans;
    }
};