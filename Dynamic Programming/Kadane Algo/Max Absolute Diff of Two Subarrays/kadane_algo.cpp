#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// inorder to find the absolute difference b/w two subarray, we can split the subarray into two halves at every index 
// for first subarray we'll find the maximum subarray sum and second subarray we'll find the minimum subarray sum or vice versa 
// will find the absolute difference b/w them and maintain the maximum among all of them 
// we can use kadane algorithm to find the maximum and minimum subarray sum 


// Link :- https://www.geeksforgeeks.org/problems/max-absolute-difference4114/1

class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();
        int maxSum = INT_MIN, sum1 = 0;
        int minSum = INT_MAX, sum2 = 0;
        vector<int> rightMaxSum(n), rightMinSum(n);
        
        // right to left traversal 
        for(int i=n-1; i>=0; --i){
            // kadane algo to find maximum sum 
            sum1 += arr[i];
            maxSum = max(maxSum, sum1);
            if(sum1 < 0){
                sum1 = 0;
            }
            rightMaxSum[i] = maxSum; 
            
            // kadane algo to find minimum sum 
            sum2 += arr[i];
            minSum = min(maxSum, sum2);
            if(sum2 > 0){
                sum2 = 0;
            }
            rightMinSum[i] = minSum;
            
        }
        
        maxSum = INT_MIN, sum1 =0;
        minSum = INT_MAX, sum2 = 0;
        
        int res = 0;
        
        // left to right traversal 
        for(int i=0; i<n; ++i){
            // kadane algo to find maximum sum 
            sum1 += arr[i];
            maxSum = max(maxSum, sum1);
            if(sum1 < 0){
                sum1 = 0;
            }
            int diff = INT_MIN;
            if(i+1 < n){
                diff = max(diff, maxSum - rightMinSum[i+1]);   
            }
            
            // kadane algo to find minimum sum 
            sum2 += arr[i];
            minSum = min(maxSum, sum2);
            if(sum2 > 0){
                sum2 = 0;
            }
            if(i+1 < n){
                diff = max(diff, rightMaxSum[i+1] - minSum);
            }
            res = max(res, diff);
        }
        return res;
    }
};