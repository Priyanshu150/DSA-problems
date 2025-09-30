#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)  
// Space complexity :- O(n*m)


// Link :- https://www.geeksforgeeks.org/problems/2-d-difference-array/1

class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int m = mat.size();
        int n = mat[0].size();

        // Initialize the difference matrix
        vector<vector<int>> changes(m + 1, vector<int>(n + 1, 0));

        // Apply the operations
        for (auto& op : opr) {
            int v = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            changes[r1][c1] += v;
            changes[r1][c2 + 1] -= v;
            changes[r2 + 1][c1] -= v;
            changes[r2 + 1][c2 + 1] += v;
        }

        // Propagate changes: first row
        for (int c = 1; c < n; ++c)
            changes[0][c] += changes[0][c - 1];

        // Propagate through the rest of the matrix
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c)
                changes[r][c] += changes[r][c - 1];
            for (int c = 0; c < n; ++c)
                changes[r][c] += changes[r - 1][c];
        }

        // Apply changes to the original matrix
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                mat[r][c] += changes[r][c];
            }
        }

        return mat;
    }
};
