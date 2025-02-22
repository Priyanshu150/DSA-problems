#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// traverse the array from left to right and using DFS approach build the tree
// for current node check whether the number of dashshed is equal to level 
// if not backtrack to previous index and return a nullptr
// otherwise create a node based on the number
//  and call the left and right recursion call respectively with correct parameters 

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
    private:
    TreeNode* recoverTree(string &s, int &ind, int &n, int level){
        if(ind >= n)    return nullptr;

        int cnt = 0, prevInd = ind;
        while(ind < n && s[ind] == '-'){
            ind++;
            cnt++;
        }
        if(cnt != level){
            ind = prevInd;
             return nullptr;
        }

        int num = 0;
        while(ind<n && isdigit(s[ind])){
            num = num*10 + (s[ind] - '0');
            ind++;
        }

        TreeNode* nd = new TreeNode(num);
        nd -> left = recoverTree(s, ind, n, level+1);
        nd -> right = recoverTree(s, ind, n, level+1);
        return nd;
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size(), ind = 0;
        return recoverTree(traversal, ind, n, 0);
    }
};