#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-   
// start from the first index of the array and build a dummy tree
// check if the node follows valid bst property of not i.e. minVal <= currNode value <= min
// pass by index by reference not by value which will help to build the complete tree 
// and if it's a valid preorder then we'll reach the end of the index 

// Link :- https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

class Solution {
  private:
    void solve(int &ind, int &n, int minVal, int maxVal, vector<int> &arr){
        // If we have processed all elements, return
        if(ind >= n)
            return;
            
        // Treat the current element as the root of this subtree
        int rootVal = arr[ind];
        
        // If the current element lies between min and max,
        // it can be part of the BST
        if(minVal <= rootVal && rootVal <= maxVal){
            ind++;
            // pass the value of index by refrece to check the complete tree 
            solve(ind, n, minVal, rootVal, arr);
            solve(ind, n, rootVal, maxVal, arr);
        }
    }
  
  public:
    bool canRepresentBST(vector<int> &arr) {
        // Start from the first element in the array
        int n = arr.size(), ind = 0;
        // Set the initial min and max values
        solve(ind, n, INT_MIN, INT_MAX, arr);
        // If all elements are processed, it means the
        // array represents a valid BST
        return (ind == n);
    }
};