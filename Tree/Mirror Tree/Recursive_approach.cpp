#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Use recursive approach to traverse to each node
// For every node find the left pointer and right pointer 
// And interchange those pointer to get the desire result 
// Start changing from bottom to top that way we can change whole tree


// Link :- https://www.geeksforgeeks.org/problems/mirror-tree/1

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  private:
    Node* solve(Node* node){
        if(!node)       return nullptr;
        
        Node* leftPtr = solve(node -> left);
        Node* rightPtr = solve(node -> right);
        
        node -> left = rightPtr;
        node -> right = leftPtr;
        
        return node;
    }
  
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        solve(node);
    }
};