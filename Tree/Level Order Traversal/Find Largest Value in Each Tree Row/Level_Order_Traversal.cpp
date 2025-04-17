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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)       return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size(), maxi = INT_MIN;

            while(sz--){
                TreeNode* nd = q.front();
                q.pop();

                maxi = max(maxi, nd -> val);
                if(nd -> left)      q.push(nd -> left);
                if(nd -> right)     q.push(nd -> right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};