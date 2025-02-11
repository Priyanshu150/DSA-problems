#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// For every node have a lowerlimit and higherlimit if any node is not in the limit that tree can't be a BST
// For root node, the limit will be [-infinity, infinity]
// going on the left of node, the limit will be [lowerlimit, node->data]
// going on the right of node, the limit will be [node->data, higherlimit]


// Link :- https://www.geeksforgeeks.org/problems/check-for-bst/1

struct Node{
    int data;
    Node* left, *right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};


class Solution {
    private:
      bool isValid(Node* node, int lowerLimit, int upperLimit){
          if(!node)       return true;
          if(lowerLimit > node->data || node->data >  upperLimit)
              return false;
          
          bool left = isValid(node -> left, lowerLimit, node->data);
          bool right = isValid(node -> right, node->data, upperLimit);
          
          return left && right;
      }
    
    public:
      // Function to check whether a Binary Tree is BST or not.
      bool isBST(Node* root) {
          // Your code here
          return isValid(root, INT_MIN, INT_MAX);
      }
  };