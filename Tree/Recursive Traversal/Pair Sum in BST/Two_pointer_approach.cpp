#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Find the inorder traversal of the tree and store it in vector 
// It will be sorted apply two pointer approach to find the pair in the array

// Link :- https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
  private:
    void inorder(struct Node *root, vector<int> &in){
        if(!root)
            return;
        
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target){
        if(!root)
            return 0;
        
        vector<int> in;
        inorder(root, in);
        
        int i(0), j(in.size()-1);
        while(i<j){
            int sum = in[i]+in[j];
            if(sum == target)
                return true;
            else if(sum < target)
                i++;
            else 
                j--;
        }
        return false;
    }
};