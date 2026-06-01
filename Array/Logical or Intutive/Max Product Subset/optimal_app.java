import java.util.*

// Time complexity :- O(N)
// Space complexity :- O(1)

// Approach :- 
// -ve modulo operation can't be handled so we'll find the max negative element 
// check if 0 can be our answer using two case 
// 1) only 0's are present in the array 
// 2) 0's and only 1 -ve number is present in the array 
// if not find product of all the number by removing the max negative element 

// Link :- https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1

class Solution {
    public int findMaxProduct(int[] arr) {
        int n = arr.length;
        if(n == 1) return arr[0];

        boolean hasPos = false, hasZero = false;
        int negCnt = 0;
        int maxNeg = Integer.MIN_VALUE;
        int mod = 1000000007;

        for(int x : arr) {
            if(x == 0)         hasZero = true;
            else if(x < 0)   { negCnt++; maxNeg = Math.max(maxNeg, x); }
            else               hasPos = true;
        }

        // All elements are zero
        if(negCnt == 0 && !hasPos) return 0;

        // Only zeros + exactly one negative → best subset is {0}
        if(hasZero && negCnt == 1 && !hasPos) return 0;

        // If negCnt is odd, skip maxNeg (closest to 0) once during multiplication
        boolean skipMaxNeg = (negCnt % 2 != 0);
        boolean skipped = false;
        long prod = 1;

        for(int x : arr) {
            if(x == 0) continue;

            // skip maxNeg instead of dividing it out later
            if(skipMaxNeg && !skipped && x == maxNeg) {
                skipped = true;
                continue;
            }

            // Math.abs() ensures no negative mod issues (product is always +ve)
            // long multiplication prevents overflow
            prod = (prod * Math.abs(x)) % mod;
        }

        return (int) prod;
    }
}