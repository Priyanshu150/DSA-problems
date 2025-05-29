#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(1)              

// Approach :- 
// traverse the tree using preorder traversal and maintain a level and sum variable
// When we reach at leaf node, If we're are at more depper level then update maxLevel and res with sum
// otherwise if previously observed max level is same as the current level then update res = max(res, sum)

// Links :- https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    int res = 0, maxLevel = 0;
    
    void solve(Node *node, int level, int sum){
        if(!node){
            if(level > maxLevel){
                maxLevel = level;
                res = sum;
            }
            else if(level == maxLevel){
                res = max(res, sum);
            }
            return;
        }
        sum += node -> data;
        solve(node -> left, level+1, sum);
        solve(node -> right, level+1, sum);
    }
  
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        solve(root, 0, 0);
        return res;
    }
};