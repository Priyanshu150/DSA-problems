import java.util.*;

class Solution {
    // Replace #define pii with Pair class
    private static class Pair {
        int row, col;
        Pair(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }
    
    private boolean isValid(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    
    public int orangesRot(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int ones = 0, res = 0;
        Queue<Pair> q = new LinkedList<>();
        int[] dir = {-1, 0, 1, 0, -1};  
        
        // Count fresh oranges + queue rotten ones
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (mat[row][col] == 2) {
                    q.offer(new Pair(row, col));
                } else if (mat[row][col] == 1) {
                    ones++;
                }
            }
        }
        if (ones == 0) return 0;
        
        // BFS level by level
        while (!q.isEmpty()) {
            int sz = q.size();
            
            while (sz-- > 0) {
                Pair front = q.poll();
                int row = front.row;
                int col = front.col;
                
                // 4 directions: up, right, down, left
                for (int i = 0; i < 4; i++) {
                    int nrow = row + dir[i];
                    int ncol = col + dir[i + 1];
                    
                    if (isValid(nrow, ncol, n, m) && mat[nrow][ncol] == 1) {
                        q.offer(new Pair(nrow, ncol));
                        mat[nrow][ncol] = 2;  // Mark as rotten
                        ones--;
                    }
                }
            }
            res++;
        }
        
        return (ones == 0) ? res - 1 : -1;
    }
}