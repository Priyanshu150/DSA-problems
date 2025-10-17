#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// The inorder of the BST is sorted, using this property 
// we'll get the sum of greater node value first
// and start updating at the node having largest value 


// links :- https://www.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  private:
    void solve(Node* node, int &sum){
        if(!node)       return;
        
        solve(node -> right, sum);
        int temp = node -> data;
        node -> data = sum;
        sum += temp;
        solve(node -> left, sum);
    }
  
  public:
    void transformTree(Node *root) {
        // code here
        int sum = 0;
        solve(root, sum);
    }
};