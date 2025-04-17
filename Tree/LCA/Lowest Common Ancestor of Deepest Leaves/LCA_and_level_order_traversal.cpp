#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n + stack_space)

// Approach :-  
// find the deapest level of the tree using level order traversal
// apply lca concept using use depth instead of node as a parameter to find the same 
// in recursion / dfs the base case will be, if node is null then return the same 
// otherwise if we're at the deapest level then return the node itself
// find the left and right value of the subtree
// if we got value in both we'll return curr_node
// if we got only left value then return left value as answer and vice-versa
// otherwise return nullptr in all the cases 

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
    TreeNode* dfs(TreeNode* node, int curr_level, int max_depth){
        if(!node)       return node;
        if(curr_level+1 == max_depth)       return node;

        TreeNode* lt = dfs(node->left, curr_level+1, max_depth);
        TreeNode* rt = dfs(node->right, curr_level+1, max_depth);

        if(lt && rt)    return node;
        if(lt)      return lt;
        if(rt)      return rt;
        return nullptr;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            while(sz-->0){
                TreeNode* nd = q.front();
                q.pop();

                if(nd->left)    q.push(nd->left);
                if(nd->right)   q.push(nd->right);
            }
            ++level;
        }
        return dfs(root, 0, level);
    }
};