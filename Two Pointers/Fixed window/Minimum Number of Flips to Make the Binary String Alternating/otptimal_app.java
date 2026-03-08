import java.util.*

//Time complexity :- O(2*n)
//Space complexity :- O(2*n)

// Approach 
// 

//Link :- https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/

class Solution {
    public int minFlips(String s) {
        int n = s.length();
        // Double string to handle circular
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();
        
        // Create alternating patterns "0101..." and "1010..."
        for (int i = 0; i < 2 * n; i++) {
            s1.append(i%2==0 ? '0' : '1');
            s2.append(i%2==0 ? '1' : '0');
        }
        int left = 0, cnt1 = 0, cnt2 = 0, res = 2*n;

        // create a sliding window of size n i.e [left, right]
        for(int right=0; right<2*n; ++right){
            // count the non matching char in both pattern 
            if (s.charAt(right % n) != s1.charAt(right)) cnt1++;
            if (s.charAt(right % n) != s2.charAt(right)) cnt2++;

            if(right - left + 1 > n){
                // remove the non matching bits once they're removed from window 
                if (s.charAt(left % n) != s1.charAt(left)) cnt1--;
                if (s.charAt(left % n) != s2.charAt(left)) cnt2--;
                ++left;
            }
            // for window of size n, store the min answer 
            if(right - left + 1 == n){
                res = Math.min(res, Math.min(cnt1, cnt2));
            }
        }
        return res;
    }
}