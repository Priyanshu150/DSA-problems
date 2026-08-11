#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m + q*max(n,m))
// Space complexity :- O(n*m)

// Approach :-  
// maitain a prefix sum matrix which calculate the sum of ones till current index 
// for every query we'll increase the side by 2 starting from 1 
// for every side we'll check how many ones are present in the matrix using preSumMatrix

// links :- https://www.geeksforgeeks.org/problems/largest-square-in-a-binary-matrix-with-at-most-k-1s-for-multiple-queries/1

class Solution {
  private:
    bool isValid(int row, int col, int &n, int &m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
  
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> preSumMat = mat;
        
        // First row
        for(int col = 1; col < m; ++col)
            preSumMat[0][col] = mat[0][col] + preSumMat[0][col-1];
        
        // First column
        for(int row = 1; row < n; ++row)
            preSumMat[row][0] = mat[row][0] + preSumMat[row-1][0];
        
        for(int row=1; row<n; ++row){
            for(int col=1; col<m; ++col){
                preSumMat[row][col] = mat[row][col] + preSumMat[row-1][col] + preSumMat[row][col-1] - preSumMat[row-1][col-1];
            }
        }
        vector<int> res;
        
        for(auto q: queries){
            int rowSt = q[0], colSt = q[1];
            int rowEnd = q[0], colEnd = q[1];
            int side = 1, validSide = 0;
            
            while(isValid(rowSt, colSt, n, m) && isValid(rowEnd, colEnd, n, m)){
                int countOfOnes = preSumMat[rowEnd][colEnd];
                if(colEnd - side >= 0)     countOfOnes -= preSumMat[rowEnd][colEnd-side];
                if(rowEnd - side >= 0)     countOfOnes -= preSumMat[rowEnd-side][colEnd];
                if(rowEnd - side >= 0 && colEnd - side >= 0) 
                    countOfOnes += preSumMat[rowEnd-side][colEnd-side];
                
                if(countOfOnes <= k)
                    validSide = side;
                else
                    break;
                
                side += 2;
                rowSt -= 1;
                rowEnd += 1;
                colSt -= 1;
                colEnd += 1;
            }
            if(validSide == 0)      res.push_back(-1);
            else                    res.push_back(validSide);
        }
        return res;
    }
};