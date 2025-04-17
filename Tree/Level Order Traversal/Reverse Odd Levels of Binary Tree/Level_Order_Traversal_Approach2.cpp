#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            vector<TreeNode*> level_nodes;

            while(sz-- > 0){
                TreeNode* node = q.front();
                q.pop();

                level_nodes.push_back(node);
                if(node -> left)       q.push(node -> left);
                if(node -> right)      q.push(node -> right);
            }
            if(level & 1){
                int n = level_nodes.size();
                for(int i=0; i<n/2; ++i)
                    swap(level_nodes[i] -> val, level_nodes[n-i-1] -> val);
            }
            ++level;
        }
        return root;
    }
};