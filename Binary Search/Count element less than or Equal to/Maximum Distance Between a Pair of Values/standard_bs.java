import java.util.*

// Time complexity :- O(n*log(m))
// Space complexity :- O(1)

// Approach :- 
// for every number in the nums1, we've to find the correspoding target in nums2 
// we'll use binary search to find the valid which has maximum index value 

// Links :- https://www.geeksforgeeks.org/problems/flip-bits0240/1

class Solution {
    private int bs(int[] nums2, int m, int target){
        int res = m;
        int low = 0, high = m-1;

        // standard bs 
        while(low <= high){
            int mid = low + (high - low)/2;
            // valid target
            if(target <= nums2[mid]){
                res = mid;
                low = mid+1;    // move the pointer to right side to find greater index
            }else{
                high = mid-1;   // move the pointer to left side to find a valid index
            }
        }
        return res;
    }

    public int maxDistance(int[] nums1, int[] nums2) {
        int res = 0;
        int n = nums1.length;
        int m = nums2.length;

        // traverse on the nums1 array 
        for(int i=0; i<n; ++i){
            // find the max index of element which is greater than or equal to curr number
            int j = bs(nums2, m, nums1[i]);
            if(j != m && i <= j){
                res = Math.max(res, (j-i));
            }
        }
        return res;
    }
}