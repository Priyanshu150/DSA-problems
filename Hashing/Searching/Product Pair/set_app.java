import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :- 
// store every number into the hash set 
// and seach the other number if current number divides the target completly 

// Links :- https://www.geeksforgeeks.org/problems/equal-to-product3836/1

class Solution {
    public boolean isProduct(int[] arr, long target) {
        int n = arr.length;
        Set<Long> nums = new HashSet<>();
        
        for(int i=0; i<n; ++i){
            if(target == 0 && arr[i]== 0)
                return true;
                
            if(arr[i] != 0 && (target % arr[i]) == 0){
                long newTarget = (target / arr[i]);
                if(nums.contains(newTarget))
                    return true;   
            }
            
            nums.add((long)arr[i]);
        }
        return false;
    }
}