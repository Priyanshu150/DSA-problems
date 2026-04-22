import java.util.*

// Time complexity :- O(q+n)
// Space complexity :- O(n)

// Approach :- 
// calculate the prefix sum of the array 
// using the prefix array find the sum of the range and mean value 


// Links :- https://www.geeksforgeeks.org/problems/mean-of-range-in-array2123/1

class Solution {
    public ArrayList<Integer> findMean(int[] arr, int[][] queries) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        
        int n = arr.length;
        int[] preSum = new int[n+1];
        
        // pre-maintained the prefix sum of array
        for(int i=0; i<n; ++i){
            preSum[i+1] = preSum[i] + arr[i];
        }
        
        for(int[] query: queries){
            // find the range 
            int l = query[0], r = query[1];
            // caluclate the sum of range based using presum technique
            int sum = preSum[r+1] - preSum[l];
            int cnt = (r-l+1);
            // find the mean value of the range 
            int mean = sum / cnt;
            res.add(mean);
        }
        
        return res;
    }
}