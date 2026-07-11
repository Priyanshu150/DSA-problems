import java.util.*

// Time complexity :- O(4^(n*m))
// Space complexity :- O(n*m)

// Approach :-  
// we've to try to explore every path and find the one which is longest one 
// use backtrack to explore other path which are not checked 
// use visited array to keep track of the cell already visited 


//Link :- https://www.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1

class Solution {
    private int n, m;
    private int destRow, destCol;
    private boolean[][] vis;
    private int[] dirs = {-1, 0, 1, 0, -1};
    
    // function to check whether matrix cell is valid or not 
    private boolean isValid(int row, int col){
        return (row >= 0 && col >= 0 && row < n && col < m);
    }
    
    private int solve(int row, int col, int[][] mat){
        // base case : destination is reached 
        if(row == destRow && col == destCol){
            return 0;
        }
        
        int res = (int)-1e7;
        // mark current cell as visited 
        vis[row][col] = true;
        
        // traverse on the adjancent cells
        for(int i=0; i<4; ++i){
            int nrow = row + dirs[i];
            int ncol = col + dirs[i+1];
            
            // if neighbour cell is applicable for traversal then traverse the cell 
            if(isValid(nrow, ncol) && !vis[nrow][ncol] && mat[row][col] == 1){
                // find the distance to reach to destination 
                int dist = 1 + solve(nrow, ncol, mat);
                // maintain the maixmum dist among all ways
                res = Math.max(res, dist);
            }
        }
        // backtrack to the previous state of visited array 
        vis[row][col] = false;
        return res;
    }
    
    public int longestPath(int[][] mat, int xs, int ys, int xd, int yd) {
        // source and destination itself is not reachable 
        if(mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;
        
        n = mat.length;
        m = mat[0].length;
        destRow = xd;
        destCol = yd;
        
        // maintain a visited array 
        vis = new boolean[n][m];        // auto initialized to false
        
        // use recursion to explore all ways 
        int ans = solve(xs, ys, mat);
        return (ans < 0) ? -1 : ans;
    }
}