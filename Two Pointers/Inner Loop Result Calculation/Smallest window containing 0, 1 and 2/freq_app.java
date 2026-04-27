import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(3)

// Approach :- 
// use sliding window approach and find the suitable window size of smaller length 
// keep track of the freq of each 0,1 and 2 in every window


// Links :- http://geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

class Solution {
    private boolean isValid(int freq[]){
        // check if 0,1,2 all are present in substring or not 
        if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
            return true;
        }
        return false;
    }
    
    public int smallestSubstring(String s) {
        int[] freq = new int[3];
        int n = s.length(), left = 0;
        int res = Integer.MAX_VALUE;
        
        
        for(int right=0; right<n; ++right){
            // add the contribution of char at right index 
            // i.e increase the window size 
            int num = s.charAt(right) - '0';
            freq[num]++;
            
            while(isValid(freq)){
                // update the window size 
                res = Math.min(res, right-left+1);
                
                // remove the contribution of char at left index
                // i.e. shrink the window size 
                num = s.charAt(left) - '0';
                freq[num]--;
                ++left;
            }
            
        }
        return (res == Integer.MAX_VALUE) ? -1 : res;
    }
};
