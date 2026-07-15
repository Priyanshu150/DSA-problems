import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :-  
// travese from right to left and store the non-decreasing subarray count in the corresponding index 
// in similar way we will maintain non-increasing count from left to right
// considering current element as a peak of the bitonic array which length equal to length from left + length from right - 1
// maintain maximum length among all the values 


//Link :- https://www.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1


class Solution {
    public int bitonic(int[] arr) {
        int n = arr.length;
        int[] decCnt = new int[n];      // maitain count of decreasing continous subarray length
        
        // traverse from right to left         
        for(int i=n-1; i>=0; --i){
            // check if the current element if on decreasing curve 
            if(i < n-1 && arr[i] >= arr[i+1]){
                decCnt[i] = 1 + decCnt[i+1];
            }else{
                decCnt[i] = 1;      // the default size of subarray will be 1 
            }
        }
        int incCnt = 0;
        int res = 0;
        
        // traverse from left to right 
        for(int i=0; i<n; ++i){
            // check if the current element if on increasing curve 
            if(i > 0 && arr[i] >= arr[i-1]){
                incCnt += 1;
            }else{
                incCnt = 1;     // the default size of subarray will be 1 
            }
            // find the length of current bitonic sequence 
            int len = Math.abs(incCnt + decCnt[i] - 1);
            // maintain max length 
            res = Math.max(res, len);
        }
        return res;
    }
}