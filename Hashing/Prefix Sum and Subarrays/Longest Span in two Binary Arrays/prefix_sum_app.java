import java.util.HashMap;

//Time complexity :- O(n)
//Space complexity :- O(n )

//Approach :-
// calculate the prefix sum of each array and find the diff among them 
// if the diff == 0, then it's the longest length subarray where both having same sum 
// store the difference if seen first time 
// otherwise find the length of subarray using the index stored 

// Link :- https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1


class Solution {
    public int equalSumSpan(int[] a1, int[] a2) {
        int n = a1.length;
        int preSum1 = 0, preSum2 = 0, res = 0;
        
        // hashmap stores the first occurence of each difference 
        HashMap<Integer, Integer> diffMap = new HashMap<>();
        
        for(int i=0; i<n; ++i){
            preSum1 += a1[i];
            preSum2 += a2[i];
            // diff b/w prerfix sum of bot arrays 
            int currDiff = preSum1 - preSum2;
            
            // If the current diff = 0, then all the subarrray has same sum 
            if(currDiff == 0){
                res = Math.max(res, i+1);
            }
            // check the difference is stored previous 
            else if(diffMap.containsKey(currDiff)){
                res = Math.max(res, i - diffMap.get(currDiff));
            }
            else{
                // store the difference corresponding to index 
                diffMap.put(currDiff, i);
            }
        }
        return res;
    }
}