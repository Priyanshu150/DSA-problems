#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)
// Space complexity :- O(1)

// Approach :-  
// traverse the matrix diagonal wise where after current cell move to row+1, col-1
// there will be multiple starting point i.e first col and last row 
// reverse the alternative sequence after start point changes 
// the stating point can also be first row and last column and follow same sequence 

// Link :- https://leetcode.com/problems/diagonal-traverse/

class Solution {
private:
    int m, n;
    
    vector<int> print(int row, int col, vector<vector<int>>& mat){
        vector<int> values;

        while(row < m && col >= 0){
            values.push_back(mat[row][col]);
            row += 1;
            col -= 1;
        }
        return  values;
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        bool flag = true;
        m = mat.size(), n = mat[0].size();

        for(int c=0; c<n; ++c){
            vector<int> values = print(0, c, mat);

            if(flag)
                reverse(values.begin(), values.end());
            
            for(auto val: values)
                ans.push_back(val);
            
            flag = !flag;
        }
        for(int r=1; r<m; ++r){
            vector<int> values = print(r, n-1, mat);

            if(flag)
                reverse(values.begin(), values.end());
            
            for(auto val: values)
                ans.push_back(val);
            
            flag = !flag;
        }
        return ans;
    }
};