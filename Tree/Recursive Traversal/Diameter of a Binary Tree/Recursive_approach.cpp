#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Use recusive method to calculate the diameter
// Find the left and right height of each node
// Then at every node calculate which node the longest length
// The longest length at every node will be left height + right height
// Calculate this for every node and calculate the largest diameter


// Link :- https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}

class Solution {
  private:
    int solve(Node* node, int &res){
        if(!node)       return 0;
        
        int leftHeight = solve(node->left, res);
        int rightHeight = solve(node -> right, res);
        
        res = max(res, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
  
  public:
    int diameter(Node* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};
