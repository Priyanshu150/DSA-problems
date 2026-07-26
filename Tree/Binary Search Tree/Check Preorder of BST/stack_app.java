import java.util.*;

// Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// using the property of stack try to replicate the process used in the brute force approach

// Link :- https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

class Solution {
    public boolean canRepresentBST(List<Integer> arr) {
        Stack<Integer> st = new Stack<>();
        
        // initialize the current node as minimum value 
        int root = Integer.MIN_VALUE;
        
        for(int i=0; i<arr.size(); ++i){
            // if we find a node who is on right side 
            // and similar than root, return false
            if(arr.get(i) < root)  
                return false;
            
            // if arr[i] is in right subtree of the stack 
            // keep removing items smaller than arr[i]
            // and make the last removed items as new root 
            while(!st.isEmpty() && st.peek() < arr.get(i)){
                root = st.pop();
            }
            // at this pint either stack is empty or 
            // arr[i] is smaller than root, push arr[i]
            st.push(arr.get(i));
        }
        return true;
    }
}