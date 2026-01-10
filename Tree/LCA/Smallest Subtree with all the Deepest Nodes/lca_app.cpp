#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(recursion_stack)

// Approach :-
// merging the logic of lca and level calculation we can solve this question 
// function will return the {Lca_node_address, deepest_level}
// if node is leaf then return it's addreess along with 1 as a level 
// if node is null return {null, 0}
// find the left and right subtree value and see which every is larger in terms of depth
// return that node as answer and increase the level by 1 
// if both having same deepth then root will be the lca and increase the level by 1

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
    #define pii pair<TreeNode*, int>

    pii dfs(TreeNode* node){
        // base case 
        if(!node)   return {nullptr, 0};
        // current node is a leaf node 
        if(!node->left && !node->right)
            return {node, 1};
        
        // find value of left and right subtree
        pii lt = dfs(node -> left);
        pii rt = dfs(node -> right);
        
        // left subtree has deepest levelnode 
        if(lt.second > rt.second){
            lt.second += 1;
            return lt;
        }
        // right subtree has deepest level node 
        else if(lt.second < rt.second){
            rt.second += 1;
            return rt;
        }
        // applying lca concept and increasing the level 
        // node will be lca if left and right are not null
        return {node, lt.second+1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // dfs return pair {node*, int}, node is lca and int represent deepest level
        return dfs(root).first;
    }
};