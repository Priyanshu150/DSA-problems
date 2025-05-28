#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n*m)
// Space complexity :- O(n)              

// Approach :- 


// Links :- https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<int> count_of_ones_in_row(n, 0);
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(mat[row][col] == 1){
                    count_of_ones_in_row[row] += 1;
                }
            }
        }
        
        for(int row1=0; row1<n; ++row1){
            if(count_of_ones_in_row[row1] > 1){
                for(int row2=row1+1; row2<n; ++row2){
                    int cnt = 0;
                    if(count_of_ones_in_row[row2] > 1){
                        for(int col=0; col<m; ++col){
                            if(mat[row1][col] == 1 && mat[row2][col] == 1)
                                cnt++;
                        }
                    }
                    if(cnt > 1)
                        return true;
                }
            }
        }
        return false;
    }
};


class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<int> count_of_ones_in_col(m, 0);
        
        for(int row=0; row<n; ++row){
            for(int col=0; col<m; ++col){
                if(mat[row][col] == 1){
                    count_of_ones_in_col[col] += 1;
                }
            }
        }
        
        for(int col1=0; col1<m; ++col1){
            if(count_of_ones_in_col[col1] > 1){
                for(int col2=col1+1; col2<m; ++col2){
                    int cnt = 0;
                    if(count_of_ones_in_col[col2] > 1){
                        for(int row=0; row<n; ++row){
                            if(mat[row][col1] == 1 && mat[row][col2] == 1)
                                cnt++;
                        }
                    }
                    if(cnt > 1)
                        return true;
                }
            }
        }
        return false;
    }
};