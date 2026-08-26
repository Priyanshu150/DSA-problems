import java.util.*;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// we'll find the longest consecutive sequence and (n - lcss) will be our answer
// for finding lcs we'll traverse the array from left to right and maintain max index from dp[nums[ind]] = 1 + dp[nums[ind] - 1]
// maintain the maximum lcs among all the sequence 

// links :- https://www.geeksforgeeks.org/problems/morning-assembly3038/1


class Solution {
    public int minMoves(int[] arr) {
        int n = arr.length;
        int maxSeq = 0;
        
        int[] dp = new int[n+1];
        
        for(int i=0; i<n; ++i){
            dp[arr[i]] = 1 + dp[arr[i]-1];
            maxSeq = Math.max(maxSeq, dp[arr[i]]);
        }
        return (n - maxSeq);
    }
}