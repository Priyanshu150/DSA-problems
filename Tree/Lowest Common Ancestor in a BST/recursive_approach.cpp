#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Inorder of bst is sorted, we'll use this logic and postorder traversal
// For a recursive call, we'll find the node on the left or the right and store it (lt && rt)
// Base case will be if we find the node return the node's address and if node is null then return node
// if lt is null return rt
// if rt is null return lt
// else return current node


//Link :- https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
  
class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(!root)    return nullptr;
        if(root->data == n1->data || root->data == n2->data)
            return root;
        
        Node* left = LCA(root->left, n1, n2);
        Node* right = LCA(root->right, n1, n2);
        
        if(left && right)   return root;
        if(!left)   return right;
        return left;
    }
};
