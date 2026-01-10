#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// we'll find the address of two nodes at the deepest level of the tree using level order traversal
// if only one node exist that will be our answer 
// using the address of those two, we will find the lca of both the nodes 

//link :- https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/

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
    typedef pair<TreeNode*, TreeNode*> ptt;

    ptt findNodes(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* first, *last;

        // level order traversal
        while(!q.empty()){
            int sz = q.size();      // size of current level
            first = nullptr;
            last = nullptr;

            // traverse on one level 
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                // save the current node depending on first / last node of level
                if(first == nullptr)
                    first = node;
                else    
                    last = node;
                
                // add the next level nodes into the queue 
                if(node -> left)
                    q.push(node -> left);
                
                if(node -> right)
                    q.push(node -> right);
            }
        }
        return {first, last};
    }

    TreeNode* lca(TreeNode* node, TreeNode* first, TreeNode* last){
        // base case 
        if(!node)                   return nullptr;
        // if current node is equal to either first / last pointer then return it 
        if(node == first)           return first;
        if(node == last)            return last;

        // find the left and right subtree value 
        TreeNode* left = lca(node -> left, first, last);
        TreeNode* right = lca(node -> right, first, last);
    
        // left ptr is nullptr then return right as it can be lca
        if(!left)       return right;
        // right ptr is nullptr then return left as it can be lca
        if(!right)      return left;

        // if both is not null the current node itself will lca
        return node;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // base case 
        if(!root)       return root;
        
        // find the two node at deepeset level 
        ptt it = findNodes(root);
        TreeNode* first = it.first;
        TreeNode* last = it.second;

        // only one node exist at deepest level 
        if(last == nullptr)
            return first;
        
        // lowest comon ancestor b/w these two nodes will be our answer 
        return lca(root, first, last);
    }
};