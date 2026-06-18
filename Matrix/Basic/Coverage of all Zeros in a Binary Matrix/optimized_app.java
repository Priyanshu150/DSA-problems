import java.util.*;

// Time complextiy :- O(n*m)
// Space complexity :- O(1)

// Approach :-   
// start from every end after first one is found update all the next cell having 0 having 1 coverage 
// repeat the same for all 4 direction 
// instead of traversing individual traverse left to right at once and top to bottom at once 


//Link :- https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1

class Solution {
    public int findCoverage(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int res = 0;
        
        // travere from left to right on each row 
        for(int row=0; row<n; ++row){
            boolean leftOne = false;
            boolean rightOne = false;
            
            // for each column 
            for(int col = 0; col<m; ++col){
                // find the first left 1 from left side  
                if(mat[row][col] == 1){
                    leftOne = true;
                }
                // all the 0s after that will have 1 as left cover 
                else if(leftOne){
                    res += 1;
                }
                
                // find the first right 1 from right side
                if(mat[row][m-col-1] == 1){
                    rightOne = true;
                }
                // all the 0s after that will have 1 as right cover 
                else if(rightOne){
                    res += 1;
                }
            }
        }
        
        // traverse on top to bottom on each column
        for(int col=0; col<m; ++col){
            boolean upOne = false;
            boolean downOne = false;
            
            // for each row 
            for(int row=0; row<n; ++row){
                // find the first top 1 from top side  
                if(mat[row][col] == 1){
                    upOne = true;
                }
                // all the 0s after that will have 1 as top cover 
                else if(upOne){
                    res += 1;
                }
                
                // find the first down 1 from bottom 
                if(mat[n-row-1][col] == 1){
                    downOne = true;
                }
                // all the 0s after that will have 1 as down cover 
                else if(downOne){
                    res += 1;
                }
            }
        }
        return res;
    }
}