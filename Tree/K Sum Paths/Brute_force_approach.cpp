#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2)
// Space complexity :- O(n)

// Approach :-  
// Traverse to every node and store the path till that node
// Use either postorder / preorder traversal technique
// Traverse on the path array from end and keep add each value to sum. If sum is equal to k then increment the res

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
        if(!node)   return;
        
        path.push_back(node -> data);
        
        solve(node -> left, k, res, path);
        solve(node -> right, k, res, path);
        
        int n = path.size(), sum = 0;
        for(int i=n-1; i>=0; --i){
            sum += path[i];
            if(sum == k)
                res++;
        }
        path.pop_back();
    }
  
  public:
    int sumK(Node *root, int k) {
        // code here
        int res = 0;
        vector<int> path;
        solve(root, k, res, path);
        return res;
    }
};