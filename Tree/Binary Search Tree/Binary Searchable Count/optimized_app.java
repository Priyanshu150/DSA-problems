import java.util.*;

// Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-   
// we can represent the array as a binary seach tree where every node is in the position given in array 
// middle of the array will be root and we'll split the array further and array the node 
// then we'll use bst logic and if every node is present at valid position then it's binary search otherwise not 
// we'll traverse from top to bottom of the tree main a leftVal and rightVal range 
// leftVal represents min value at least current node should have 
// rightVal represents max value a node can have 
// i.e leftVal < node_val < rightVal then it's binary searchable 


//Link :- https://www.geeksforgeeks.org/problems/binary-searchable-elements/1

class Solution {
    private int solve(int[] arr, int low, int high, int leftVal, int rightVal){
        // base case 
        if(low > high)
            return 0;
        
        int ans = 0;
        int mid = low + (high - low)/2;     // find the mid value 
        
        // answer lies in the range then it's binary searchable element 
        if(leftVal < arr[mid] && arr[mid] < rightVal){
            ans = 1;
        }
         // find the valid count of binary searchable element 
        // in the left and right subtree 
        int leftCnt = solve(arr, low, mid-1, leftVal, Math.min(rightVal, arr[mid]));
        int rightCnt = solve(arr, mid+1, high, Math.max(leftVal, arr[mid]),rightVal);
        // count all the valid elements 
        return ans + leftCnt + rightCnt;
    }
    
    public int binarySearchable(int[] arr) {
        int n = arr.length;
        return solve(arr, 0, n-1, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
};