#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        //Transpose of matrix
        for(int row=0; row<n; ++row){
            for(int col=row+1; col<n; ++col){
                int temp = mat[row][col];
                mat[row][col] = mat[col][row];
                mat[col][row] = temp;
            }
        }
        int st = 0, end = n-1;
        //Swap rows of the matrix
        while(st < end){
            for(int i=0; i<n; ++i){
                int temp = mat[st][i];
                mat[st][i] = mat[end][i];
                mat[end][i] = temp;
            }
            st++;
            end--;
        }
    }
};
