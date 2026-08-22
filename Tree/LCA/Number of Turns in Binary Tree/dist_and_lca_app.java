import java.util.*;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Instead of starting from one node to another 
// find the lca of both the nodes and caluclate the distance in terms of left or right direction 
// then find the distance till the both node from lca including the turn logic 
// subtract 1 for initial distance and that will be the total turns 
// if the turn is equal to 0 then return -1 for that 

// links :- https://www.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1

class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = right = null;
    }
} 

class Solution {
    private Node findLCA(Node node, int p, int q) {
        // base case 
        if(node == null) return null;
        // node value to given p 
        if(node.data == p || node.data == q)
            return node;
        
        // find the left lca value 
        Node leftVal  = findLCA(node.left,  p, q);
        Node rightVal = findLCA(node.right, p, q);
        
        // if any of the value is null return the other 
        if(leftVal  == null) return rightVal;
        if(rightVal == null) return leftVal;
        
        // if both are not null, the current node is LCA
        return node;
    }
    
    
    private int findTurnTo(Node node, int target, int direction) {  
        // base case 
        if(node == null)        return 100000;  
        // node is equal to target
        if(node.data == target)
            return 0;
        
        // find the total distance taken to target 
        int leftTurn  = findTurnTo(node.left,  target, 0);
        int rightTurn = findTurnTo(node.right, target, 1);
        
        // if we're making a turn then update the count 
        leftTurn  += (direction == 0) ? 0 : 1;
        rightTurn += (direction == 1) ? 0 : 1;
        
        // return the min distance take 
        return Math.min(leftTurn, rightTurn);
    }
    
    public int numberOfTurns(Node root, int p, int q) {
        // find the lca of both node
        Node lca = findLCA(root, p, q);
        // find the lca to both node distacne and subtract 1 
        // 1 because initally we start with any turn 
        int res = findTurnTo(lca, p, -1) + findTurnTo(lca, q, -1) - 1;
        // no turn found then return -1 
        return (res == 0) ? -1 : res;
    }
}