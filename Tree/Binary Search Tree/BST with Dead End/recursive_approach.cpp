#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n - stack_space)

// Approach :-  
// find the range of each node using the property of BST 
// At leaf node, check if the node has a range greater than 1 
// if it does then it's not a dead end otherwise it's a dead end 


// Link :- https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1 

class Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    bool solve(Node *node, int leftRange, int rightRange){
        if(!node)       return false;
        
        if(!node->left && !node->right){
            int range = rightRange - leftRange -1;
            if(range == 1)      return true;
            return false;
        }
        bool lt = solve(node -> left, leftRange, node -> data);
        bool rt = solve(node -> right, node -> data, rightRange);
        
        return lt || rt;
    }
  
  public:
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root, 0, 1e5+1);
    }
};
