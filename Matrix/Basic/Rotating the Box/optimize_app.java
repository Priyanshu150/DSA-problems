import java.util.*

// Time complexity :- O(n*m + m*n)
// Space complexity :- O(1)

// Approach :-  
// rotate the matrix by 90 degree 
// start count the stones from bottom to top 
// maintain a space variable to point to next avaialbe swap
// whenever we get the stone we'll skip it with the last space 
// or we get the stationary object then we'll update the last space 

// Links :- https://leetcode.com/problems/rotating-the-box/

class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {
        int m = boxGrid.length;
        int n = boxGrid[0].length;
        char[][] ans = new char[n][m];
        
        // traverse the matrix by 90 
        for(int row=m-1; row>=0; --row){
            for(int col=0; col<n; ++col){
                char ch = boxGrid[row][col];
                ans[col][m-row-1] = ch;
            }
        }

        // update the stones based on prefix sum matrix 
        for(int col=0; col<m; ++col){
            int lastSpacePos = n-1;

            for(int row=n-1; row>=0; --row){
                if(ans[row][col] == '*'){
                    lastSpacePos = row-1;
                    continue;
                }
                if(ans[row][col] == '#'){
                    ans[row][col] = '.';
                    ans[lastSpacePos][col] = '#';
                    lastSpacePos--;
                }
            }
        }
        return ans;
    }
}