import java.util.*

// Time complexity :- O(m*n*k)
// Space complexity :- O(m*n*k)

// Approach :- 
// we've to try all the possibilities, to find the maximum value of grid 
// (row, col, cost) will be changing parameter 
// all possibilities, move left and down with valid cost 
// choose the maximum possible value from both case 
// base case will be when we reach at last grid or when cost becomes more than k 
// memoize the solution using 3d dp 

// Links :- https://leetcode.com/problems/maximum-path-score-in-a-grid/

class Solution {
    private int solve(int row, int col, int cost, int[][] grid, int k, int[][][] dp) {
        int val = grid[row][col];
        
        // Calculate cost and score for the CURRENT cell
        int currCost = (val == 1 || val == 2) ? 1 : 0;
        int currScore = (val == 1) ? 1 : (val == 2 ? 2 : 0);

        // If taking this cell puts us over budget, this path is invalid
        if (cost + currCost > k) return -100000;

        // Base case: Reached the start
        if (row == 0 && col == 0) {
            return currScore;
        }

        // Memoization check
        if (dp[row][col][cost] != -1) {
            return dp[row][col][cost];
        }

        int up = -100000;
        int left = -100000;

        // Move Left
        if (col - 1 >= 0) {
            left = solve(row, col - 1, cost + currCost, grid, k, dp);
        }
        // Move Up
        if (row - 1 >= 0) {
            up = solve(row - 1, col, cost + currCost, grid, k, dp);
        }

        // The score of this cell + the best score from the remaining path
        int result = Math.max(left, up) + currScore;
        return dp[row][col][cost] = result;
    }

    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        
        // Correct dimensions: [rows][cols][cost]
        int[][][] dp = new int[m][n][k + 1];
        for (int[][] mat : dp) {
            for (int[] row : mat) {
                Arrays.fill(row, -1);
            }
        }

        int ans = solve(m - 1, n - 1, 0, grid, k, dp);
        
        // If ans is still a large negative number, no path was found within budget k
        return (ans < 0) ? -1 : ans;
    }
}