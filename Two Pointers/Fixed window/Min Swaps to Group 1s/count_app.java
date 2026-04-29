import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :- 
// count the total number of one in the completed array 
// Find the maximum number of one in the array having fixed window size of total number of one in array 
// (totalOne - maxOne) from a window will be our final answer to swap the number of 0s 


// Links :- https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1

class Solution {
    public int minSwaps(int[] arr) {
        int totalOnes = 0;
        int n = arr.length;
        
        // count the number of one in the array 
        for(int i=0; i<n; ++i){
            if(arr[i] == 1){
                totalOnes++;
            }
        }
        // no one exist 
        if(totalOnes == 0)
            return -1;
        
        int maxOnes = 0, left = 0, ones = 0;
        
        // maintain a fixed window of totalOnes size 
        for(int right=0; right<n; ++right){
            if(arr[right] == 1){
                ones++;
            }
            
            if(right >= totalOnes){
                if(arr[left] == 1){
                    ones--;
                }
                left++;
            }
            maxOnes = Math.max(maxOnes, ones);
        }
        // total num of ones - max number of ones will be the swap needed 
        return (totalOnes - maxOnes);
    }
}

