#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2)
// Space complexity :- O(n)

// Approach :-  
// store the node in top-down format into the array 
// traverse from end to st of array after post-traversal of every node 
// if we found the sum, matain a counter to keep track of the sum 
// backtrack the previous node, in-order to remove it from the other path 

// Link :- https://www.geeksforgeeks.org/problems/k-sum-paths/1

struct Node {
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
    void solve(Node *node, int &k, int &res, vector<int> &path){
        // base case 
        if(!node)   return;

        // add current node into the ds 
        path.push_back(node -> data);
        
        // traverse on the subtree 
        solve(node -> left, k, res, path);
        solve(node -> right, k, res, path);
        
        int n = path.size(), sum = 0;
        // find the sum from end of the node to top
        for(int i=n-1; i>=0; --i){
            sum += path[i];
            // if it exists, store the number of times it does 
            if(sum == k)
                res++;
        }
        // backtack
        path.pop_back();
    }
  
  public:
    int sumK(Node *root, int k) {
        int res = 0;
        vector<int> path;
        solve(root, k, res, path);
        return res;
    }
};