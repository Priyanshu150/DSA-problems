#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n*log(n))
// Space complexity :- O(1)

// Approach :-  
// following the same approach what questions mention 
// traversing on the diagonal, next pointer will be row+1 & col+1
// starting point will be first row and col 

// link :- https://leetcode.com/problems/sort-matrix-by-diagonals/

class Solution {
private:
    void sortMatrixByDiagonal(int row, int col, vector<vector<int>>& grid, int &n, bool inc){
        int r = row, c = col, ind = 0;
        vector<int> temp;

        while(r<n && c<n){
            temp.push_back(grid[r][c]);
            r++;
            c++;
        }
        if(inc)
            sort(temp.begin(), temp.end());
        else 
            sort(temp.begin(), temp.end(), greater<int> ());

        r = row, c=col;
        while(r<n && c<n){
            grid[r][c] = temp[ind];
            ind++;
            r++;
            c++;
        }
    }

public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int row=n-1; row>=0; --row){
            sortMatrixByDiagonal(row, 0, grid, n, false);
        }
        for(int col=1; col<n; ++col){
            sortMatrixByDiagonal(0, col, grid, n, true);
        }
        return grid;
    }
};

