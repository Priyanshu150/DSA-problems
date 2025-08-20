#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(n*m))
//Space complexity :- O(1)

// Approach :-   
// Same as rotated binary search approach of 1D array 
// Convert the value of mid, low and high to row and col 


//link :- https://www.geeksforgeeks.org/problems/search-in-fully-rotated-sorted-2d-matrix/1

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n*m - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int row = mid/m, col = mid%m;
            int row1 = low/m, col1 = low%m;
            int row2 = high/m, col2 = high%m;
            
            if(mat[row][col] == x)
                return true;
            else if(mat[row1][col1] <= mat[row][col]){
                if(mat[row1][col1] <= x && x <= mat[row][col])
                    high = mid-1;
                else 
                    low = mid+1;
            }
            else{
                if(mat[row][col] <= x && x <= mat[row2][col2])
                    low = mid+1;
                else 
                    high = mid-1;
            }
        }
        return false;
    }
};
