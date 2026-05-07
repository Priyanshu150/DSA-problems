import java.util.*

// Time complexity :- O(n)
// Space complexity :- O(1)

// Approach :-  
// make a searilize function which make the tree / subtree in code format 
// code the S tree using that 
// code every node to leaf node of T tree using that 
// if any of the subtree matches with the code then it's present otherwise it's not 

// Links :- https://www.geeksforgeeks.org/problems/check-if-subtree/1


class Node {
    int data;
    Node left;
    Node right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}

class Solution {
    private String S;
    private boolean ans; 
    
    private String codeString(Node node, int nodeVal){
        // base case 
        if(node == null){
            return "";
        }
        
        // find the left and right code 
        String lt = codeString(node.left, nodeVal);
        String rt = codeString(node.right, nodeVal);
        // decode the current tree into the code 
        String newCode = node.data + "L" + lt + "R" + rt;
         // match the current node with S subtree 
        if((node.data == nodeVal) && (newCode.equals(S))) {
            ans = true;
        }
        
        return newCode;
    }
    
    public boolean isSubTree(Node root1, Node root2) {
        ans = false;
        S = "";
        // code the S tree into string 
        S = codeString(root2, -1);
        // code the T tree into string 
        codeString(root1, root2.data);
        return ans;
    }
}
