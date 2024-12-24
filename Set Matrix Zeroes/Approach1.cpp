#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<bool> row_Containing_Zero(n, false), col_Containing_Zero(m, false);
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(mat[row][col] == 0){
                    row_Containing_Zero[row] = true;
                    col_Containing_Zero[col] = true;
                }
            }
        }
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(row_Containing_Zero[row] || col_Containing_Zero[col])
                    mat[row][col] = 0;
            }
        }
    }
};