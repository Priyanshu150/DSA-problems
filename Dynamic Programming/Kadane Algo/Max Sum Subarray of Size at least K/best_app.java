import java.util.*

// Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-   
// instead of storign the value of maximum sum we maintain it on the go 
// when every sum turns out to be 0 outside the window we switch it back to 0 and start again 


// Link :- https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1

class Solution {
    public int maxSumWithK(int[] arr, int k) {
        int sum = 0;
        int n = arr.length;
        
        for(int i=0; i<k; ++i)
            sum += arr[i];
        
        int j = 0;
        int last = 0;
        int maxSum = sum;
        
        for(int i=k; i<n; ++i){
            // add current element 
            sum += arr[i];
            // add current element to sum outside window
            last += arr[j++];
            // update the maximum sum till now 
            maxSum = Math.max(maxSum, sum);
            
            // subarray sum outside window is negative
            if(last < 0){
                sum = (sum - last);
                maxSum = Math.max(maxSum, sum);
                last = 0;
            }
        }
        return maxSum;
    }
}