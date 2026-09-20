
// Time complexity :- O(n^3)
// Space complexity :- O(n^2)

// Approach :- 
// 1. We will use prefix sum technique to calculate the number of X's in the left and up direction for each cell in the matrix.
// 2. We will traverse the matrix from bottom right to top left and for each cell, we will calculate the maximum size of the subsquare that can be formed with that cell as the bottom right corner.
// 3. We will check if the boundary of the subsquare has the required number of X's in the left and up direction. If it does, we will update the maximum size of the subsquare found so far.   


//Link :- https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1

class Solution {
    public int largestSubsquare(char mat[][]) {
        int n = mat.length;
        
        int[][] left = new int[n][n];
        int[][] up = new int[n][n];
        
        // traverse on each cell of the matrix 
        for(int row=0; row<n; ++row){
            for(int col=0; col<n; ++col){
                // current cell value is X
                if(mat[row][col] == 'X'){
                    // prefix sum technique
                    left[row][col] = ((col == 0) ? 1 : left[row][col-1] + 1);
                    up[row][col] = ((row == 0) ? 1 : up[row-1][col] + 1);
                }
            }
        }
        int maxSize = 0;
        
        for(int row=n-1; row>=0; --row){
            for(int col=n-1; col>=0; --col){
                // calculate the max size possile for the matrix
                int maxSide = Math.min(up[row][col], left[row][col]);
                
                // try to explore for all valid size
                for(int size=maxSide; size > 0; --size){
                    // check if the boundary has requried X or not 
                    if(left[row-size+1][col] >= size && up[row][col-size+1] >= size){
                        // update the maximum size 
                        maxSize = Math.max(size, maxSize);
                        break;
                    }
                }
            }
        }
        return maxSize;
    }
};