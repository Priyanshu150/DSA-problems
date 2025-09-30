#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)  
// Space complexity :- O(n*n)

// Approach :- 
// find the sum of each row and each col. Among them find the max_sum
// now we have to make every row and col sum equal to max_sum
// for that either we traverse on each column or matrix 
// and start adding the number which is deficit in that row 


// Link :- https://www.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), max_sum = 0, res = 0;
        vector<int> row_sum(n, 0), col_sum(n, 0);
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<n; ++col){
                row_sum[row] += mat[row][col];
                col_sum[col] += mat[row][col];
                max_sum = max({max_sum, row_sum[row], col_sum[col]});
            }
        }
        for(int row=0; row<n; ++row){
            int target = max_sum - row_sum[row], col = 0;
            while(target > 0 && col < n){
                int req = max_sum - col_sum[col];
                int opn = min(req, target);
                target -= opn; 
                row_sum[row] += opn;
                col_sum[col] += opn;
                res += opn;
                col++;
            }
        }
        return res;
    }
};