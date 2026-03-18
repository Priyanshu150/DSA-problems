import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :- 
// we've to calculate how much movement of candies have to be done in complete tree 
// we'll use post order traversal for that 
// we keep track of all the movement in a variable which will be the sum of subtree candies 
// current node will keep 1 candy and rest it will pass to the parent 

// Code :- 

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {
    private int res;
    
    private int solve(Node node){
        // base case
        if(node == null)    
            return 0;
        
        // find the coin the have to move to from left subtree 
        int coinFromLeft = solve(node.left);
        // find the coin the have to move to from right subtree 
        int coinFromRight = solve(node.right);
        
        // total movement will be sum from both subtree 
        res += Math.abs(coinFromLeft) + Math.abs(coinFromRight);
        
        // current node will keep 1 coins and rest all it will pass to it parent node
        return (node.data + coinFromLeft + coinFromRight - 1);
    }
    
    public int distCandy(Node root) {
        res = 0;
        solve(root);
        return res;
    }
}