#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*n)  
// Space complexity :- O(n*m)

// Approach :-
// Use presum technique, make a temporary matrix for maintain sum
// for each operation, go on each row from r1 to r2 and mark temporary matrix 
// at c1 with +val and c2+1 with -val, take matrix column size of +1 to handle c2+1 
// And later traverse on the matrix and temporary matrix and using prefix sum technique update it


// Link :- https://www.geeksforgeeks.org/problems/2-d-difference-array/1

class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> temp(n, vector<int> (m+1, 0));
        
        for(auto opn: opr){
            int val = opn[0], r1 = opn[1], c1 = opn[2], r2 = opn[3], c2 = opn[4];
            for(int r=r1; r<=r2; ++r){
                temp[r][c1] += val;
                temp[r][c2+1] -= val;
            }
        }
        
        for(int row=0; row<n; ++row){
            int sum = 0;
            for(int col=0; col<m; ++col){
                sum += temp[row][col];
                mat[row][col] += sum;
            }
        }
        return mat;
    }
};