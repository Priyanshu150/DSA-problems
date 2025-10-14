#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Use recusion to solve this, since it's BST we can use the property of the same 
// if the data of node is in the range then add that to result and explore left and right sub-tree
// if l value greater than node's data then explore right subtree 
// if r value less than node's data then explore left subtree


// Link :- https://www.geeksforgeeks.org/problems/range-sum-of-bst/1

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
*/

class Solution {
  public:
    int nodeSum(Node* node, int l, int r) {
        // code here
        if(!node)   return 0;
        
        int sum = 0;
        if(l <= node -> data && node -> data <= r){
            sum += node -> data;
            sum += nodeSum(node -> left, l, r);
            sum += nodeSum(node -> right, l, r);
        }
        else if(l > node -> data){
            sum += nodeSum(node -> right, l, r);
        }
        else if(r < node -> data){
            sum += nodeSum(node -> left, l, r);   
        }
        return sum;
    }
};
