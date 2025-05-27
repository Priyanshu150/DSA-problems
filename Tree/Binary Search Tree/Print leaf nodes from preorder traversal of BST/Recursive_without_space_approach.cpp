#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(1)              

// Approach 
// BST property :- Left value <= Root's value <= right value 
// similarly in preorder we'll have (root , left, right) 
// if current node is considered as root then on left side the node having smaller value will be in left subtree
// use recursion to apply above logic
// Consider current node as root node, find the index which is greater than root
// call the left-subtree and right-subtree respectively
// base case will be when no nodes present then return from that point
// if 1 node present then that will be leaf node


// Links :- https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

class Solution {
  private:
    void solve(int start, int end, vector<int> &preorder, vector<int> &res){
        if(start > end)     return;
        if(start == end){
            res.push_back(preorder[start]);
            return;
        }
        
        int val = preorder[start], ind = start+1;
        while(ind <= end && preorder[ind] < val){
            ++ind;
        }
        solve(start+1, ind-1, preorder, res);
        solve(ind, end, preorder, res);
    }
  
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n = preorder.size();
        vector<int> res;
        solve(0, n-1, preorder, res);
        return res;
    }
};