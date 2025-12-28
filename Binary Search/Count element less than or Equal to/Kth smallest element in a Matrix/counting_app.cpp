#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n * log(max_ele - min_ele))
//Space complexity :- O(1) 

// Approach :-
// the answer will lie b/w min and max element of the matrix 
// for every number we'll count the number of element less that or equal to mid value 
// if the count is greater that k, then that can be our answer also try to decrese it more 
// otherwise we'll try to increase our answer 
// for counting, we can start from top_right element of the matrix 
// try to decrease the col value until value greater than mid 
// once it's equal or less, count the numbers and move down the row 
// that way repeat it for every column and don't reset column pointer 
// in this way we've to only traverse O(n) to find the count 
// since it's row-wise and col-wise sorted we can count using this approach it'll work 

//link :- https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

lass Solution {
  private:
    int countSmallerEqual(int num, vector<vector<int>> &mat, int &n){
        int cnt = 0, row = 0, col = n-1;
        
        // start from top-right corner of the matrix 
        while(row < n && col >= 0){
            // current element is larger the move left 
            if(mat[row][col] > num){
                col -= 1;
            }
            // otherwise move down
            else{
                cnt += (col+1);
                row += 1;
            }
        }
        return cnt;
    }
  
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int low = mat[0][0], high = mat[n-1][n-1], res = high;
        
        // standard bs
        while(low <= high){
            int mid = low + (high - low)/2;
            // count the number of element less than or equal to mid 
            int cnt = countSmallerEqual(mid, mat, n);
            
            if(cnt < k){
                low = mid+1;
            }else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};