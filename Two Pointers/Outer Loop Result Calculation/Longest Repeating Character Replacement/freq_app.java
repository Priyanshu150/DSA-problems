import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(26)

// Approach :- 
// count the freq of each char in every window, maintain a sliding window 
// find out the maximum freq of char and total char in substring 
// if deficit b/w then is less than k then it's a valid window otherwise it's not 
// if it's not valid, then decrement the window size 
// if it's valid, then increment the window size 


// Links :- https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1

class Solution {
    private boolean isValid(int freq[], int k){
        int maxi = 0, sum = 0;
        
        for(int i=0; i<26; ++i){
            if(freq[i] > 0){
                // sum of all the freq 
                sum += freq[i];
                // maintain the maximum freq 
                maxi = Math.max(maxi, freq[i]);
            }
        }
        // deficit b/w sum and maxi is less than k then it's valid window otherwise it's not
        return !((sum - maxi) <= k);
    }
    
    public int longestSubstr(String s, int k) {
        int n = s.length();
        int left = 0, res = 0;
        int[] freq = new int[26];
        
        for(int right=0; right<n; ++right){
            // add the contribution of current char 
            char ch = s.charAt(right);
            freq[ch - 'A'] += 1;
            
            // make window valid by decreasing the size of window 
            while(isValid(freq, k)){
                // remove the char from left side of window 
                ch = s.charAt(left);
                freq[ch - 'A'] -= 1;
                
                ++left;
            }
            // update the length of valid window 
            res = Math.max(res, right - left + 1);
        }
        return res;
    }
}

