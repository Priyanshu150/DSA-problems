#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n = stack_space)

// Approach :-  
// Match nodes at a time from same tree, start from left and right child of root node
// apply preorder technique to check the node data first and then exploring their corresponding child
//  to check mirroring property for right match with left and vice-versa of both the nodes 
// the base cases will be, if both are null that means it's true 
// otherwise if anyone is null and others are present then that's might not satisfy our property


// Link :- https://www.geeksforgeeks.org/problems/symmetric-tree/1

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  private:
    bool solve(Node* n1, Node* n2){
        if(!n1 && !n2)      return true;
        if(!n1 || !n2)      return false;
        if(n1 -> data != n2 -> data)
            return false;
        
        bool b1 = solve(n1 -> left, n2 -> right);
        bool b2 = solve(n1 -> right, n2 -> left);
        return b1 & b2;
    }
  
  public:
    bool isSymmetric(Node* root) {
        // Code here
        return solve(root->left, root->right);
    }
};