import java.util.*;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// traverse from 1 to n 
// count the number of bit that will be present in the number 
// shift ans than number of time and add the curr_number to answer 

// Link :- https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

class Solution {
    private int numOfBits(int num){
        if(num == 0)        return 1;
        return Integer.toBinaryString(num).length();
    }

    public int concatenatedBinary(int n) {
        long res = 0;
        final int mod = 1000000007;

        // traverse from 1 to n 
        for(int num=1; num<=n; ++num){
            // count the length of bits num have 
            int bits = numOfBits(num);
            // left shift the number by bits times and add num
            res = (res << bits) + num;
            // modulo by highest number 
            res %= mod;
        }
        return (int)res;
    }
}