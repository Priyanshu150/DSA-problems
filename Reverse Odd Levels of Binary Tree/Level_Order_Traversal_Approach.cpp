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
private:
    void reverseNodes(TreeNode* root, queue<TreeNode*> q){
        int sz = q.size();
        vector<int> nodes;

        for(int i=0; i<sz; ++i){
            TreeNode* node = q.front();
            q.pop();
            nodes.push_back(node -> val);
            q.push(node);
        }
        reverse(nodes.begin(), nodes.end());
        int ind = 0, n = nodes.size();

        for(int i=0; i<sz; ++i){
            TreeNode* node = q.front();
            q.pop();
            if(ind < n){
                node -> val = nodes[ind];
                ind++;
            }
            q.push(node);
        }
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            if(level % 2)       reverseNodes(root, q);

            while(sz-- > 0){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left)       q.push(node -> left);
                if(node -> right)      q.push(node -> right);
            }
            ++level;
        }
        return root;
    }
};