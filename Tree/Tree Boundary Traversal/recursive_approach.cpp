#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Traverse left boundary then leaves and then right boundary
// First go on left subtree if root has left subtree (go on left if left not exist then go on right)
// Then traverse on all the leaf node and put them into ans data structure
// Last visit the right subtree if root has right subtree presnt (go on right if right not exist then go on left)

// Link :- https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

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
  private:
    void leftBoundary(Node* node, vector<int> &ans){
        if(!node)   return;
        if(!node -> left && !node -> right)     return;
        
        ans.push_back(node -> data);
        if(node -> left){
            leftBoundary(node -> left, ans);
            return;
        }
        leftBoundary(node -> right, ans);
    }
    
    void leafNodes(Node* node, vector<int> &ans){
        if(!node)       return;
        if(!node->left && !node->right)
            ans.push_back(node -> data);
        
        leafNodes(node -> left, ans);
        leafNodes(node -> right, ans);
    }
    
    void rightBoundary(Node* node, vector<int> &ans){
        if(!node)   return;
        if(!node->left && !node->right)     return;
        
        if(node->right)         rightBoundary(node -> right, ans);
        else                    rightBoundary(node -> left, ans);
        
        ans.push_back(node -> data);
    }
  
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root)   return ans;
        
        ans.push_back(root->data);
        if(!root->left && !root->right)     return ans;
        
        leftBoundary(root -> left, ans);
        leafNodes(root, ans);
        rightBoundary(root -> right, ans);
        
        return ans;
    }
};