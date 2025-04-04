#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(stack_space)

// Approach :-  
// We can have height based approach to solve this problem in single traversal
// if the height of left subtree(lt) is equal to height of right subtree(rt) then the current will be lca
// if lt < rt, then lca can be find on right subtree as it has more depth
// if lt > rt, then lca can be find in left subtree as it has more depth
// return type of dfs traversal will be {lca, depth} a pair
// we can solve this problem through bottom up approach
// base cases, when node == nullptr return {null, 0} 
// node is leaf node then return {node, 1}


//Link :- https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};