#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int minSwap(vector<int> &values){
        int n = values.size(), cnt = 0;
        vector<int> sorted = values;
        sort(sorted.begin(), sorted.end());     // Sorting

        unordered_map<int,int> mp;
        
        for(int i=0; i<n; ++i)
            mp[values[i]] = i;          //Hashing

        for(int i=0; i<n; ++i){
            //Checking for the values 
            if(values[i] != sorted[i]){
                // If not same check for the which should be at originial pos and swap
                int pos = mp[sorted[i]];
                swap(values[i], values[pos]);
                mp[values[i]] = i;
                mp[values[pos]] = pos;
                cnt++;
            }
        }
        return cnt;
    }

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        //Level order traversal
        while(!q.empty()){
            int sz = q.size();
            vector<int> values;

            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                values.push_back(node -> val);
                if(node -> left)        q.push(node -> left);
                if(node -> right)       q.push(node -> right);
            }
            res += minSwap(values);
        }
        return res;
    }
};