#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-

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
        if(!node)   return {nullptr, 0};
        if(!node->left && !node->right)
            return {node, 1};
        
        pii lt = dfs(node -> left);
        pii rt = dfs(node -> right);

        if(lt.second > rt.second){
            lt.second += 1;
            return lt;
        }
        else if(lt.second < rt.second){
            rt.second += 1;
            return rt;
        }
        return {node, lt.second+1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};