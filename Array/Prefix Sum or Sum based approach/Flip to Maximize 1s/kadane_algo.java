import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :- 
// convert 0's to +1 andd 1's to -1 and apply kadane algo on the array 
// and record the range for [left, right] for the maximum answer 
// update the final sum of the range 

// Links :- https://www.geeksforgeeks.org/problems/flip-bits0240/1

class Solution {
    int maxOnes(int[] arr) {
        int n = arr.length;
        int left = 0, right = -1;
        int rangeLeft = -1, rangeRight = -1;
        int currSum = 0, totalSum = 0, maxSum = 0;
        
        
        // kadanes algorithm 
        for(int i=0; i<n; ++i){
            // overall sum of array 
            totalSum += arr[i];
            
            // sum of the current element 
            if(arr[i] == 1){
                currSum -= 1;
            }else{
                currSum += 1;
            }
            
            // update the max sum 
            if(currSum > maxSum){
                maxSum = currSum;
                right = i;
                
                // update the range 
                rangeLeft = left;
                rangeRight = right;
            }
            // curr sum becomes -ve 
            if(currSum < 0){
                // update the sum and left details 
                currSum = 0;
                left = i+1;
            }
        }
        // all 1's value 
        if(rangeLeft == -1)
            return totalSum;
        
        // upate the final sum for the range 
        for(int i=rangeLeft; i<=rangeRight; ++i){
            if(arr[i] == 1){
                totalSum -= 1;
            }else{
                totalSum += 1;
            }
        }
        return totalSum;
    }
};