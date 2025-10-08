#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// we'll use recursive approach to build the tree
// The first element of the preoder will be root of the tree 
// And the 2nd element will be the part of left subtree
// we will find the index(ind) of same 2nd element in postorder 
// And we will find a length using that ind - starting index of preorder 
// and subsequently we'll call for the other cases using recurions for left and right child of tree
// base case will be when we've no element or only 1 element


// Link :- 
// (leetcode) https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
// (gfg) https://www.geeksforgeeks.org/problems/construct-tree-from-preorder-postorder/1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  private:
    unordered_map<int,int> mp;  // mapping post_value to index
    
    Node* solve(int preSt, int preEnd, vector<int> &pre, int postSt, int postEnd, 
    vector<int> &post){
        
        if(preSt > preEnd || postSt > postEnd)
            return nullptr;
        
        if(preSt == preEnd && postSt == postEnd)
            return new Node(pre[preSt]);
        
        // make the root node 
        Node* root = new Node(pre[preSt]);
        // find the left child
        int ind = mp[pre[preSt+1]];
        // calculate the number of nodes in left child 
        int numOfNode = ind - postSt + 1;
        
        // left child formation
        root -> left = solve(preSt+1, preSt+numOfNode, pre, postSt, ind, post);
        // right child formation 
        root -> right = solve(preSt+numOfNode+1, preEnd, pre, ind+1, postEnd-1, post);
        
        return root;
    }
    
  public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int n = pre.size();
        // mapping value to index
        for(int i=0; i<n; ++i)
            mp[post[i]] = i;
        
        return solve(0, n-1, pre, 0, n-1, post);
    }
};