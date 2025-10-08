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
    unordered_map<int,int> mp;

    TreeNode* solve(int prs, int pre, int pos, int poe, vector<int>& preorder){
        if(prs > pre || pos > poe)
            return nullptr;
        
        if(prs == pre || pos == poe)
            return new TreeNode(preorder[prs]);
        
        TreeNode* nd = new TreeNode(preorder[prs]);
        int ind = mp[preorder[prs+1]], len = ind - pos + 1;

        nd -> left = solve(prs+1, prs+len, pos, ind, preorder);
        nd -> right = solve(prs+len+1, pre, ind+1, poe, preorder);
        return nd;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i=0; i<n; ++i)
            mp[postorder[i]] = i;
        
        return solve(0, n-1, 0, n-1, preorder);
    }
};