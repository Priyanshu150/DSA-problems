#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// replication the recursive approach using stack approach
// use stack to keep track of all the node and for for level find the size of stack 

// Link :- https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

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
    public:
    TreeNode* recoverFromPreorder(string s) {
        int ind = 0, n = s.size();
        stack<TreeNode*> st;

        while(ind < n){
            int count = 0;
            while(ind<n && !isdigit(s[ind])){
                ind++;
                count++;
            }
            int depth = st.size();
            while(depth > count){
                st.pop();
                depth--;
            }
            int val = 0;
            while(ind < n && isdigit(s[ind])){
                val = val*10 + (s[ind] - '0');
                ind++;
            }

            TreeNode* node = new TreeNode(val);
            if(!st.empty()){
                if(st.top() -> left == nullptr)
                    st.top() -> left = node;
                else 
                    st.top() -> right = node;
            }
            st.push(node);
        }
        while(st.size() > 1)
            st.pop();

        return st.top();
    }
};