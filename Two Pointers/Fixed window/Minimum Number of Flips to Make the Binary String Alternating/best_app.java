import java.util.*

//Time complexity :- O(2*n)
//Space complexity :- O(1)

// Approach 
// 

//Link :- https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/


class Solution {
    public int minFlips(String s) {
        int n = s.length(), res = 2*n;
        int left = 0, cnt1 = 0, cnt2 = 0;

        // create a sliding window of size n i.e [left, right]
        for(int right=0; right<2*n; ++right){
            // find what should be the char at right index at s1 and s2 
            char charExpectedAtS1 = (right%2==0 ? '0' : '1');
            char charExpectedAtS2 = (right%2==0 ? '1' : '0');

            // count the non matching char in both pattern 
            if (s.charAt(right % n) != charExpectedAtS1) cnt1++;
            if (s.charAt(right % n) != charExpectedAtS2) cnt2++;

            if(right - left + 1 > n){
                // find what should be the char at left index at s1 and s2 
                charExpectedAtS1 = (left%2==0 ? '0' : '1');
                charExpectedAtS2 = (left%2==0 ? '1' : '0');

                // remove the non matching bits once they're removed from window 
                if (s.charAt(left % n) != charExpectedAtS1) cnt1--;
                if (s.charAt(left % n) != charExpectedAtS2) cnt2--;
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
