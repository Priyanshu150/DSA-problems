import java.util.*;

// Time complextiy :- O(n^2)
// Space complexity :- O(n)

// Approach :-  
// check the validity of the tree using BST property 
// first node will always be root as preOrder traversal is given
// find the first value after that which is greater that will be starting of right node 
// if any node find smaller value in the right subtree section then return false

// Link :- https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

class Solution {
    private boolean solve(List<Integer> arr, int left, int right){
        // base case: 0 or 1 node is present 
        if(left >= right)       return true;
        
        int j = left + 1;
        // traverse to the strating point of right subtree
        while(j <= right && arr.get(j) < arr.get(left)){
            j++;
        }
        
        // check the nodes in right subtree whether they are valid or not 
        for(int i=j; i<=right; ++i){
            // node in right subtree is smaller than root node 
            if(arr.get(i) < arr.get(left)){
                return false;
            }
        }
        return solve(arr, left+1, j-1) && solve(arr, j, right);
    }
    
    public boolean canRepresentBST(List<Integer> arr) {
        int n = arr.size();
        return solve(arr, 0, n-1);
    }
}