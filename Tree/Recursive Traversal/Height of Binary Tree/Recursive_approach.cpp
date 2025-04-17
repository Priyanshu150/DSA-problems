#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Find the height using recusion 
// for base case, if node == nullptr then height will be 0
// For every node find the left and right tree height
// Whichever is maximum consider that one and return the height by adding 1 to it denoting the current node

// Link :- https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    int findHeight(Node* node){
        if(!node)       return 0;
        
        int leftHeight = findHeight(node -> left);
        int rightHeight = findHeight(node -> right);
        
        return 1 + max(leftHeight, rightHeight);
    }
  
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        if(!node)       return 0;
        
        return findHeight(node)-1;
    }
};