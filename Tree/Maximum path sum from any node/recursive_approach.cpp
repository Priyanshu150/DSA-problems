#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// For any node, the maximum path will be the left's maximum sum path + node's data + right's maximum sum path
// Use recursive approach to traverse to each node, use Postorder traversal
// Find the max left sum path and max right sum path 
// calculate the max sum path as mention above 
// check wheather left path has max sum or right path has max sum
// After determining that add root data to the same and return for every node
// Because we can only carry one path going futher it should be maximum
// If the selection give's us -ve path sum then return 0

// Link :- https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    private:
      int solve(Node* node, int &res){
          if(!node)       return 0;
          
          int leftSum = solve(node -> left, res);
          int rightSum = solve(node -> right, res);
          
          res = max(res, node -> data + leftSum + rightSum);
          return max(0, node -> data + max(leftSum, rightSum));
      }
    
    public:
      // Function to return maximum path sum from any node in a tree.
      int findMaxSum(Node *root) {
          // code here
          int res = INT_MIN;
          solve(root, res);
          return res;
      }
  };