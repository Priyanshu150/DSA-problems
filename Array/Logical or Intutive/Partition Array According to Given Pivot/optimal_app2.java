import java.util.*

// Time complexity :- O(n+n)
// Space complexity :- O(n)

// Approach :- 
// traverse from left and right both side 
// from left if less element found update it in answer array 
// from right if greater element found update it in answer array 
// if gap exist b/w left and right then middle element will be pivot only 

// Link :- https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int st = 0, end = n-1;
        int res[] = new int[n];

        for(int i=0; i<n; ++i){
            int j = n-1-i; // other pair of index 

            // current element is less than pivot 
            if(nums[i] < pivot){
                // add the element to res array and increase the start pointer 
                res[st] = nums[i];
                ++st;
            }
            // current element is greater than pivot element 
            if(nums[j] > pivot){
                // add the element to res array and decrease the end pointer 
                res[end] = nums[j];
                end--;
            }
        }
        // in remaining gap, pivot element will be present 
        for(int i=st; i<=end; ++i){
            res[i] = pivot;
        }
        return res;
    }
}