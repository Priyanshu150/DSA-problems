import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :- 
// for every node we've to find which is the largest and smallest node value in the subtree 
// if current node satisfies the property of left -> maxval <= node->data <= right -> minVal
// then it will be a BST and count of nodes and be also update using the same 
// we'll use post order traversal to find the maximum value required value from both subtree 
// and then the result can be calculate for the same 

// Code :- 

class Node{
    int data;
    Node left, right;

    public Node(int d){
        data = d;
        left = right = null;
    }
}

class BSTInfo {
    int mini;
    int maxi;
    int mxSz;

    BSTInfo(int mn, int mx, int sz) {
        mini = mn;
        maxi = mx;
        mxSz = sz;
    }
}

class Solution {
    // Recursive Function to find maximum size
    static BSTInfo largestBSTBT(Node root) {
        if (root == null)
            return new BSTInfo(Integer.MAX_VALUE, Integer.MIN_VALUE, 0);

        BSTInfo left = largestBSTBT(root.left);
        BSTInfo right = largestBSTBT(root.right);

        // Check if the current subtree is a BST
        if (left.maxi < root.data && right.mini > root.data) {
            return new BSTInfo(Math.min(left.mini, root.data),
                               Math.max(right.maxi, root.data),
                               1 + left.mxSz + right.mxSz);
        }

        return new BSTInfo(Integer.MIN_VALUE, Integer.MAX_VALUE, Math.max(left.mxSz, right.mxSz));
    }
    
    // Return the size of the largest sub-tree which is also a BST
    static int largestBst(Node root) {
        // Write your code here
        return largestBSTBT(root).mxSz;
    }
}