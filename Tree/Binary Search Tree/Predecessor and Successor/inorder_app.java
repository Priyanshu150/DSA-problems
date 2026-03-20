import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :- 
// inorder of BST is sorted in increasing order, we can use that to find the predecessor and successor 

// link :- https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

class Node {
    int data;
    Node left, right;
    Node(int x) {
        data = x;
        left = right = null;
    }
}

class Solution {
    private static class NodeRef{
        Node node;
        
        NodeRef(Node node){
            this.node = node;
        }
    }
    
    private static void solve(Node node, int key, NodeRef pred, NodeRef succ){
        // base case 
        if(node == null)
            return;
        
        // using standard postorder traversal 
        solve(node.left, key, pred, succ);
        
        // update the predecessor until we find the larget one
        if(node.data < key){
            pred.node = node;
        }
        // update the successor whichever is found first time 
        if(succ.node == null && node.data > key){
            succ.node = node;
        }
        solve(node.right, key, pred, succ);
    }
    
    public ArrayList<Node> findPreSuc(Node root, int key) {
        // Intialize predecessor and succesor with null using a class 
        // so that it can be passwed by reference
        NodeRef pred = new NodeRef(null);
        NodeRef succ = new NodeRef(null);
        
        solve(root, key, pred, succ);
        
        // add the answer to the list 
        ArrayList<Node> result = new ArrayList<>();
        result.add(pred.node);
        result.add(succ.node);
        return result;
    }
}