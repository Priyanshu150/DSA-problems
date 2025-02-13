#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(k)

// Approach :-  
// Inorder traversal of BST is sorted form of traveral for tree
// Start cnt the number and once you reach kth number return the result

// Link :- https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

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
    int res, cntOfEle;
    
    void inorder(Node* node, int &k){
        if(!node)       return;
        if(res != -1)   return;
        
        inorder(node -> left, k);
        
        cntOfEle += 1;
        if(cntOfEle == k){
            res = node -> data;  
            return;
        }
        
        inorder(node -> right, k);
    }
  
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        res = -1, cntOfEle = 0;
        inorder(root, k);
        return res;
    }
};