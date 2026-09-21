
// Time complexity :- O(n*k)
// Space complexity :- O(k)

// Approach :- 
// 1. We will use dynamic programming to keep track of the count of subsequences for each remainder when divided by k.
// 2. We will maintain an array prevCount where prevCount[rem] will store
//   the count of subsequences that give a remainder rem when divided by k.
// 3. For each number in the input array, we will create a new array currCount to store the updated counts of subsequences for each remainder.
// 4. We will iterate through each number in the input array and for each remainder rem
//  in prevCount, we will calculate the new remainder newRem when the current number is multiplied with the subsequences that give remainder rem.



//Link :- https://leetcode.com/problems/find-x-value-of-array-i/description/

class Solution {
    public long[] resultArray(int[] nums, int k) {
        int n = nums.length;

        long[] result = new long[k];
        long[] prevCount = new long[k];

        for(int i=0; i<n; ++i){
            long[] currCount = new long[k];

            currCount[nums[i] % k] += 1;

            for(int rem=0; rem<k; ++rem){
                int newRem = (int) (((long) rem * nums[i] % k) % k);
                currCount[newRem] += prevCount[rem];
            }
            prevCount = currCount;

            for(int x=0; x<k; ++x){
                result[x] += prevCount[x];
            }
        }
        return result;
    }
}  