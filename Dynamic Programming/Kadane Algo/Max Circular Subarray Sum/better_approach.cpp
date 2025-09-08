#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)  
// Space complexity :- O(1)

// Approach :- 
// using kadanes algo we can find the maximum sum for the array with wrap 
// for finding the wrap sum we can change the array by multiply each number by -1 
// that way when applying kadanes algorithm we'll get the minimum sum for previous array
// and we can subtract the sum_of_array with minimum sum to get wrap around sum 
// non_wrap_sum = sum_of_array - ( -1 * maximum_sum_of_modified_array)
// take the maximum value of non_wrap_sum and wrap_sum as answer 


// Link :- https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

class Solution {
  private:
    int kadane(vector<int> &arr){
        int sum = 0, res = INT_MIN;
        
        for(auto num: arr){
            sum += num;
            res = max(res, sum);
            if(sum < 0)     sum = 0;
        }
        return res;
    }
  
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int nonWrapSum = kadane(arr), sum = 0;
        if(nonWrapSum < 0)      return nonWrapSum;
        
        for(auto &num: arr){
            sum += num;
            num *= -1;
        }
        
        int wrapSum = sum + kadane(arr);
        for(auto &num: arr)
            num *= -1;
        
        return max(wrapSum, nonWrapSum);
    }
};