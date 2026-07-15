import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :-  
// traverse on the increasing curve until present 
// traverse on the decreasing curve util present 
// maintain a start point, next start point will be index after the peak 
// maintain the maximum among all and update the start index 


//Link :- https://www.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1

class Solution {
    public int bitonic(int[] arr) {
        int n = arr.length;
        if(n == 0)      return 0;
        
        int j = 0;
        int start = 0;
        int maxLen = 1;
        int nextStart = 0;
        
        while(j < n-1){
            // traverse on the increasing curve 
            while(j < n-1 && arr[j] <= arr[j+1])
                ++j;
            
            // traverse on decreasing curve
            while(j < n-1 && arr[j] >= arr[j+1]){
                // next array can start just after peak 
                if(j < n-1 && arr[j] > arr[j+1])
                    nextStart = j+1;
                
                ++j;
            }
            // maintain maximum among all subarray 
            maxLen = Math.max(maxLen, j-start+1);
            // update the next starting point 
            start = nextStart;
        }
        return maxLen;
    }
}