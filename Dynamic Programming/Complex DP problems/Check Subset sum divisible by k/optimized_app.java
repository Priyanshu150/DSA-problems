import java.util.*

//Time complextiy :- O(n*k)
// Space complexity :- O(k)

// Approach :-  
// In order to get the optimize the solution, we'll keep track of all the subset sum % k seen till now in dp array 
// in the current state we'll for a subset with only current element i.e. single element
// the sum with all the previous subset sum previous observed 
// at any point we encountered the subset sum = 0 then it's possible 


//Link :- https://www.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1

class Solution {
    public boolean divisibleByK(int[] arr, int k) {
        // stores achievable remainders modulo k 
        boolean[] dp = new boolean[k];
        
        for(int num: arr){
            // new remainder formed using arr[i]
            boolean[] next = dp.clone();
            // using current element for a single element subset
            next[num % k] = true;
            
            // check all the previous subset value 
            for(int rem=0; rem<k; ++rem){
                // check the subset sum which was previously found
                if(dp[rem] == true){
                    // find the next subset sum by combining the current element 
                    int nextVal = (rem + num) % k;
                    // make that subset sum true in the array 
                    next[nextVal] = true;
                }
            }
            // subset with divisible sum found 
            if(next[0] == true)
                return true;
                
            // update the dp with new remainder 
            dp = next;
        }
        return dp[0];
    } 
}