#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// find the sum of the nodes in the tree 
// and then try to delete each edge and find the product of sum of splitted trees 
// for finding the sum of two tree, current node data + left subtree sum + right subtree sum
// will give the sum of tree from current node till leaf and when we subtract it from overall sum
// we'll get the sum of other tree, that way we can try all the solutions 

//link :- https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

class Solution {
private:
    int findSumOfTree(TreeNode* node){
        // base case 
        if(!node)       return 0;

        // overall sum will be node value, sum of left subtree and sum of right subtree
        int sum = node -> val;
        sum += findSumOfTree(node -> left);
        sum += findSumOfTree(node -> right);

        return sum;
    }

    int solve(TreeNode* node, int &sum, long long &res){
        if(!node)       return 0;;

        // sum of left subtree 
        int left = solve(node -> left, sum, res);
        // sum of right subtree
        int right = solve(node -> right, sum , res);

        // overall subtree sum = node's val + left + right
        int subSum = node -> val + left + right;
        // break the current edge and make two subtrees and find the product of them
        long long prod = (long long)subSum*(sum-subSum);
        res = max(res, prod);

        return subSum;
    }

public:
    int maxProduct(TreeNode* root) {
        // find sum of the tree nodes 
        int sum = findSumOfTree(root), mod = 1e9+7; 
        long long res = 0;
        // maximum product among all the pairs 
        solve(root, sum, res);
        return res % mod;
    }
};