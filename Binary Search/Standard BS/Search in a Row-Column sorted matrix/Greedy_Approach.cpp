#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N+M)
//Space complexity :- O(1)

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n = mat.size(), m = mat[0].size();
        int row = 0, col = m-1;
        
        while(row < n && col >= 0){
            if(mat[row][col] == x)
                return true;
            else if(mat[row][col] < x)
                row++;
            else
                col--;
        }
        return false;
    }
};