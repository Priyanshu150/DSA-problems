#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Use recusive approach to solve the problem have states (inorderStartInd, inorderEndInd, preOrderStartInd, preOrderEndInd)
// Construct the first node of tree which will at preOrderStartInd
// Find the index at which preorder[preOrderStartInd] is present in inorder seq (use hashing for optimised approach)
// For left node and right node call the recursion with modified index depending on the finding 
// return node address for general case and construct a base case to stop the recursion


// Link :- https://www.geeksforgeeks.org/problems/construct-tree-1/1

// Definition of the Node class
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
    unordered_map<int,int> mp;
  
    Node* solve(int is, int ie, int ps, int pe, vector<int> &inorder, vector<int> &preorder){
        if(is > ie || ps > pe)        return NULL;
        
        Node* node = new Node(preorder[ps]);
        int ind = mp[preorder[ps]], len = ind-is;
        
        node -> left = solve(is, ind-1, ps+1, ps+len, inorder, preorder);
        node -> right = solve(ind+1, ie, ps+len+1, pe, inorder, preorder);
        
        return node;
    }
  
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = inorder.size();
        
        for(int i=0; i<n; ++i)
            mp[inorder[i]] = i;
        
        return solve(0, n-1, 0, n-1, inorder, preorder);
    }
};