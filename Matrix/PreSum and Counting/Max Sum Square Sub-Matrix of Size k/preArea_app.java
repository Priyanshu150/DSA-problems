import java.util.*

// Time complexity :- O(n*m)
// Space complexity :- O(n*m)

// Approach :- 

// Links :- https://www.geeksforgeeks.org/problems/coins-of-geekland--141631/1

class Solution {
    public int maximumSum(int[][] mat, int k) {
        int n = mat.length;
        int[][] preArea = new int[n][n];
        
        preArea[0][0] = mat[0][0];
        
        // fill the first row 
        for(int row=1; row<n; ++row){
            preArea[row][0] = (preArea[row-1][0] + mat[row][0]);
        }
        // fill the first column 
        for(int col=1; col<n; ++col){
            preArea[0][col] = (preArea[0][col-1] + mat[0][col]);
        }
        
        // calculate the area of rest of the cell 
        for(int row=1; row<n; ++row){
            for(int col=1; col<n; ++col){
                int area = mat[row][col] + preArea[row-1][col] + preArea[row][col-1] - preArea[row-1][col-1];
                preArea[row][col] = area;
            }
        }
        int res = Integer.MIN_VALUE;
        
        // calculate the area of every sub-matrix of size k*k
        for(int row=k-1; row<n; ++row){
            for(int col=k-1; col<n; ++col){
                int area = preArea[row][col];
                
                if(col - k >= 0)    area -= preArea[row][col-k];
                if(row - k >= 0)    area -= preArea[row-k][col];
                if((col - k) >= 0 && (row - k) >= 0)
                    area += preArea[row-k][col-k];
                
                res = Math.max(area, res);
            }
        }
        return res;
    }
}