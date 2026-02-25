import java.util.HashMap;

//Time complexity :- O(n)
//Space complexity :- O(n)

//Approach :-
// consider number greater than k as +1 and other as -1
// hence we've to find the subarray having positive sum 
// we can apply prefix sum techique to find the subarry 
// store the sum and index pair in the hashset 
// if sum > 0, then i+1 will be the subarray 
// otherwise find the (sum-1) in the set and caluclate the subarray length using that 
// store the first occurence of the sum into hashset with index 
// why sum-1 ? (sum - (sum-1)) = 1 which will give us first positive sum 

// Link :- https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1


class Solution {
    public int longestSubarray(int[] arr, int k) {
        int n = arr.length;
        // store {sum, index} in hashmap 
        HashMap<Integer, Integer> mp = new HashMap<>();
        int ans = 0, sum = 0;
        
        for(int i=0; i<n; ++i){
            // add the contribution of +ve as +1 and -ve as -1
            if(arr[i] > k){
                sum += 1;
            }else{
                sum -= 1;
            }
            
            // sum is +ve means 1's > 0's 
            if(sum > 0){
                ans = i+1;
            }
            // otherwise check if sum-1 exist
            else if(mp.containsKey(sum - 1)){
                // using hashing, find the length 
                ans = Math.max(ans, i - mp.get(sum - 1));
            }
            if(!mp.containsKey(sum)){
                // hash the relevant details 
                mp.put(sum, i);
            }
        }
        return ans;
    }
}
