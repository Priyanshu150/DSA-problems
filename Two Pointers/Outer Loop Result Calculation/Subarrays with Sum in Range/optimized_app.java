import java.util.*

// Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-   
// for find the count of subarray in range [l, r]
// find the count of subarray <= r 
// find the count of subarray <= l-1
// subtract both of them to get the actual count 

// Link :- https://www.geeksforgeeks.org/problems/count-the-number-of-subarrays/1

class Solution {
    private int countSumLessThanOrEqualToTarget(int[] arr, int n, int target){
        int count = 0;
        int sum = 0;
        int left = 0;
        
        for(int right=0; right<n; ++right){
            sum += arr[right];
            
            while(target < sum){
                sum -= arr[left];
                ++left;
            }
            count += (right - left + 1);
        }
        return count;
    }
    
    public int countSubarray(int[] arr, int l, int r) {
        int n = arr.length;
        
        int leftCount = countSumLessThanOrEqualToTarget(arr, n, l-1);
        int rightCount = countSumLessThanOrEqualToTarget(arr, n, r);
        
        return rightCount - leftCount;
    }
}