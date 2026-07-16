import java.util.*;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// simulate the process given in the question 


// Link :- https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/

class Solution {
    private long gcd(long a, long b){
        return (b == 0) ? a : gcd(b, a%b);
    }

    public long gcdSum(int[] nums) {
        int n = nums.length;
        long maxi = 0;
        long[] prefixGcd = new long[n];

        for(int i=0; i<n; ++i){
            maxi = Math.max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        Arrays.sort(prefixGcd);

        int left = 0;
        int right = n-1;
        long res = 0;

        while(left < right){
            res += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return res;
    }
}