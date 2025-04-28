#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// we can use recursion and further memoize it to avoid repeating sub-problems 
// one of the case will be we take current_node and take all the grand child if exist 
// other case will be take the sum of left and right child value 
// the answer will be max value of both the case 


//link :- https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
    unordered_map<Node*, int> dp;
    
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // BASE CASE 
        if(!root)   return 0;
        
        // MEMOIZE
        if(dp[root])    return dp[root];
        
        // WITH NODE 
        int with = root -> data;
        if(root -> left){
            with += getMaxSum(root -> left -> left);
            with += getMaxSum(root -> left -> right);
        }
        if(root -> right){
            with += getMaxSum(root -> right -> left);
            with += getMaxSum(root -> right -> right);
        }
        
        // WITHOUT NODE 
        int without = getMaxSum(root->left) + getMaxSum(root->right);
        
        return dp[root] = max(with, without);
    }
};