import java.util.*

//Time complextiy :- O(n*k*2)
// Space complexity :- O(n*k*2)

// Approach :-  
// try all ways to take and not-take every element of the array and form the sum of the array 
// if at last the sum is divisible by k then it's possible otherwise it's not 
// we can do modulo of sum with k, so that sum will be in the range of (0 to k-1)
// also take a vairable which keep track of whether the subset taken was empty or not 
// memoize the solution using 3d dp of [n*k*2] 


//Link :- https://www.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1


class Solution {
    private int[][][] dp;
    
    private int solve(int ind, int sum, boolean isEmpty, int k, int[] arr){
        // base case: no element present 
        if(ind == 0){
            // check if the subset is empty
            if(isEmpty) return 0;
            // subset sum is not divisible by k
            if(sum % k != 0) return 0;
            // otherwise it's possible
            return 1;
        }
        // convert isEmpty to int index for dp lookup
        int emptyInd = isEmpty ? 1 : 0;
        
        // return cached result if already computed 
        if(dp[ind][sum][emptyInd] != -1){
            return dp[ind][sum][emptyInd];
        }
        
        // not take the current element and move to the next one 
        int notTake = solve(ind-1, sum, isEmpty, k, arr);
        // take the current elemnt add to the sum, update that subset is not empty and move to the next
        int take = solve(ind-1, (sum + arr[ind-1]) % k, false, k, arr);
        // check if any two possibility of above gives us correct answer
        return dp[ind][sum][emptyInd] = notTake | take;
    }
    
    public boolean divisibleByK(int[] arr, int k) {
        int n = arr.length;
        // dp[ind][sum][isEmpty] = -1 (unvisited), 0(false), 1(true)
        dp = new int[n+1][k][2];
        
        for(int[][] layer: dp){
            for(int[] row: layer){
                Arrays.fill(row, -1);
            }
        }
        return solve(n, 0, true, k, arr) == 1;
    }
}
