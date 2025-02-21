#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :- 
// Use BFS to traverse the binary tree and recover it
// Use a hashset to store TreeNode->val for finding

// Link :- https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements {
    private:
    unordered_set<int> st;

public:
    FindElements(TreeNode* root) {
        st.clear();
        recoverBinaryTree(root);
    }

    void recoverBinaryTree(TreeNode* root){
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});

        while(!q.empty()){
            TreeNode* nd = q.front().first;
            int val = q.front().second;
            q.pop();

            nd -> val = val;
            st.insert(val);

            if(nd -> left)
                q.push({nd->left, 2*val+1});
            
            if(nd -> right)
                q.push({nd->right, 2*val+2});
        }
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */