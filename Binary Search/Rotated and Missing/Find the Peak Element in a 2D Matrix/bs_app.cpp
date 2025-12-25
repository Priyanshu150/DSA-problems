#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(m))
//Space complexity :- O(1) 

// Approach :-
// for finding the peak in 2-d array, we'll use the concept of 1-d array 
// we'll apply binary search on column 
// for each column we'll find the maximum value index and check if that's peak or not 
// if peak is on the left side, we'll eliminate the right half i.e high = mid-1
// if peak is on the right side, we'll eliminate the left half i.e low = mid+1
// if left side is larger than current element then peak is on left otherwise right 
// peak will be on the side which has larger value because 
//  we'll eventually find a larger value or the first or last column value 

//link :- https://www.geeksforgeeks.org/problems/find-the-peak-element-in-a-2d-matrix/1

class Solution {
  private:
    int findMaxEleRow(int col, vector<vector<int>> &mat, int &n){
        int maxVal = INT_MIN, rowNo = -1;
        
        // find the max value in the row where col is fixed
        for(int row=0; row<n; ++row){
            if(mat[row][col] > maxVal){
                maxVal = mat[row][col];
                rowNo = row;
            }
        }
        return rowNo;
    }
  
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1; 
        
        // standard bs
        while(low <= high){
            int mid = low + (high - low)/2;
            // find the max element row 
            int row = findMaxEleRow(mid, mat, n);
            // find the left and right value of the current column 
            int left = (mid-1) >= 0 ? mat[row][mid-1] : INT_MIN;
            int right = (mid+1) < m ? mat[row][mid+1] : INT_MIN;
            
            // current element if the peak 
            if(left <= mat[row][mid] && right <= mat[row][mid]){
                return {row, mid};
            }
            // peak is on the left side 
            else if(left > mat[row][mid]){
                high = mid-1;
            }
            // peak is on the right side 
            else{
                low = mid+1;
            }
        }
        return {-1, -1};
    }
};

