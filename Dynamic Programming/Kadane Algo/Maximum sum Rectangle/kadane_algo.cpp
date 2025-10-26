#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n*m^2)
// Space Complexity: O(n)

// Approach :- 
// Find the presum of either column or row 
// fix either 2 col or row depending on the sum taken from the row or column
// and create a presum of array of row or column size 
// use kadane's algo to find the maximum sum on that array 

// Link :- https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1

class Solution {
  private:
    int kadane(vector<int> &arr, int &sz){
        int maxSum = INT_MIN, sum = 0;
        
        for(int i=0; i<sz; ++i){
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
  
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size(), maxSum = INT_MIN;
        
        for(int cs=0; cs<m; ++cs){
            vector<int> rowSum(n, 0);
            for(int ce=cs; ce<m; ++ce){
                for(int row=0; row<n; ++row){
                    rowSum[row] += mat[row][ce];
                }
                
                maxSum = max(maxSum, kadane(rowSum, n));
            }
        } 
        return maxSum;
    }
};