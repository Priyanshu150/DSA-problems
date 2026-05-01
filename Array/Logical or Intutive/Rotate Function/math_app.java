import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :- 
// we can find the sum of the array and value arr[i]*i of the array
// for finding the moving rotational value of the array, we've travers on each value 
// and apply this value (prevValue + totalSum - n * currVal)
// every number roated by 1 hence totalSum is added 
// and we've to substract (n*currVal) as it moves to zeros 

// Links :- https://leetcode.com/problems/rotate-function/

class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        int totalSum = 0;
        int prevVal = 0;
        
        for(int i=0; i<n; ++i){
            // sum of the array 
            totalSum += nums[i];
            // sum of nums[i]*i
            prevVal += (nums[i] * i);
        }
        int ans = prevVal;

        for(int i=n-1; i>0; --i){
            // find the rotating value of function 
            int newVal = prevVal + totalSum - (n*nums[i]);
            // update the maximum answer 
            ans = Math.max(ans, newVal);
            prevVal = newVal;
        }
        return ans;
    }
}