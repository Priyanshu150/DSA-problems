#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*n*m*m)
// Space complexity :- O(1)              

// Approach :- 


// Links :- https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        for(int col1=0; col1<m; ++col1){
            for(int row1=0; row1<n; ++row1){
                if(mat[row1][col1] == 1){
                    for(int row2=row1+1; row2<n; ++row2){
                        if(mat[row2][col1] == 1){
                            for(int col2=col1+1; col2<m; ++col2){
                                if(mat[row1][col2] == 1 && mat[row2][col2] == 1)
                                    return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};