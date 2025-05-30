#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(log(n))
// Space complexity :- O(recursion_stack_space)              

// Approach :- 
// Using the property of BST, maintain a res variable to track the result 
// if the curr node value is less than the given value, explore the left subtree
// otherwise explore the right subtree


// Links :- https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    void solve(Node* node, int &k, int &ans){
        if(!node)   return;
        
        if(node -> data <= k){
            ans = max(node -> data, ans);
            solve(node -> right, k, ans);
            return;
        }
        solve(node -> left, k, ans);
    }
  
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};