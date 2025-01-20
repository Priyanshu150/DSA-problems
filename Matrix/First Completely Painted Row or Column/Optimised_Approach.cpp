#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*M)
// Space complexity :- O(1)

//Approach :- 
// Traverse the matrix and save the {row, col} of value
// While traverse the array find the {row, col} of matrix based on value which we stored earlier
// Start marking which row & col are painter
// A row is completely painted when all the column inside it is painted 
// Similar a col is completely painted when all the row inside it is painted
// When either of the condition satisfies check whichever index we're standing at is our answer

//Link :- https://leetcode.com/problems/first-completely-painted-row-or-column/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, pair<int,int>> mp;

        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                mp[mat[row][col]] = {row, col};
            }
        }
        vector<int> rowsPainted(n, 0), colsPainted(m, 0);

        for(int i=0; i<(n*m); ++i){
            int row = mp[arr[i]].first;
            int col = mp[arr[i]].second;

            rowsPainted[row] += 1;
            colsPainted[col] += 1;

            if(rowsPainted[row]==m || colsPainted[col] == n)
                return i;
        }
        return 0;
    }
};