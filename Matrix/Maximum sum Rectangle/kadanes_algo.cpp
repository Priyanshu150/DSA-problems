#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m*m*n)  
// Space complexity :- O(n)

// Approach :-
// we'll use kadanes algo to find the maximum sum 
// we can fix two pair of column or rows and then find the sum for the respective cell 
// and for that cell find the maximum sum using kadanes algo
// in this case we fixed the column's pair and find the sum for each row and then max sum on that 
// the sub matrix for us will be the column's pair 
// and row's pair which will be the index where the maximum sum lies in the array formed 


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
