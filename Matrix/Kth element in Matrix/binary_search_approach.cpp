#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(ele)*n)
// Space complexity :- O(1)

//Approach :- 
// apply binary search, low will be matrix[0][0] and high will be matrix[n-1][n-1]
// For every mid element find the number of element smaller than that number
// if cout is less than k which mean we need to increase the number that means low = mid+1
// otherwise save the current ans and decrease the number i.e. high = mid-1

// to calculate the number of element less than a particular number use a function
// in that function start with the last element of first row
// if matrix value is less than given val add the number(col+1) in count and move down the row
// otherwise decrease the col value


//Link :- https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

class Solution {
  private:
    int lessThanK(vector<vector<int>> &matrix, int val, int &n){
        int row = 0, col = n-1, cnt = 0;
        
        while(row < n && col >= 0){
            if(matrix[row][col] <= val){
                cnt += (col+1);
                row++;
            }
            else{
                col--;
            }
        }
        return cnt;
    }
    
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size(), low = matrix[0][0], high = matrix[n-1][n-1], ans = high;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int count = lessThanK(matrix, mid, n);
            
            if(count < k)
                low = mid+1;
            else{
                high = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};