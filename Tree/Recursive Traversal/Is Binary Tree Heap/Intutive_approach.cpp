#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(height(BT))

// Approach :-  
// we've to handle to cases completeness and max-heap-property if these both satisfies then it's a heap
// for checking completness we'll capture the height whenever we get the first nullptr
// whenever we find the the next nullptr on the same level where previously node was present 
// we'll mark the variable as false in the base case 
// when we find more height in the next path then we return false stating that completeness is not possible
// or when we found a node at a same level as that of maxLevel and 'found' is true then return false
// going top to down pass the node value to child nodes
// if the curr_node value is greater than node value got from parent then return false stating it can't be max heap
// find the left and right value of the tree and return (lt && rt) value
// to check if both left subtree or right subtree is valid max heap or not


//link :- https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    bool found = false;
  
    bool solve(Node* node, int level, int maxValue, int &maxLevel){
        if(!node){
            if(maxLevel == -1){
                maxLevel = level;
            }
            else if(maxLevel < level || (maxLevel == level && found))
                return false;
            else if(maxLevel > level)
                found = true;
            
            return true;
        }
        if(node -> data > maxValue)      return false;
        
        bool lt = solve(node -> left, level+1, node -> data, maxLevel);
        bool rt = solve(node -> right, level+1, node -> data, maxLevel);
        
        return (lt & rt);
    }
  
  public:
    bool isHeap(Node* tree) {
        // code here
        if(!tree)
            return true;
        
        int maxLevel = -1;
        return solve(tree, 0, INT_MAX, maxLevel);
    }
};
