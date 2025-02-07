#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Using recursive approach traverse on the tree
// traverse left subtree then push the node in ans and then traverse right subtree
// Repeat this for every node

// Link :- https://www.geeksforgeeks.org/problems/inorder-traversal/1

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
  private:
    void solve(Node* node, vector<int> &ans){
        if(!node)       return;
        
        solve(node -> left, ans);
        ans.push_back(node -> data);
        solve(node -> right, ans);
    }
  
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};