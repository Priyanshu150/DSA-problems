#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// using the property of BST, we'll check if the current node value is 
// less than l value, discard the left subtree
// greater than r value, discard the right subtree
// rewrite the left and right node value of current tree node
// return the node
// use recursion to achieve the same result 


// Link :- https://www.geeksforgeeks.org/problems/remove-bst-keys-outside-given-range/1

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        if(!root)
            return nullptr;
        
        Node* ltNode = removekeys(root -> left, l, r);
        Node* rtNode = removekeys(root -> right, l, r);
        
        int val = root -> data;
        if(val < l)     return rtNode;
        if(val > r)     return ltNode;
        
        root -> left = ltNode;
        root -> right = rtNode;
        
        return root;
    }
};