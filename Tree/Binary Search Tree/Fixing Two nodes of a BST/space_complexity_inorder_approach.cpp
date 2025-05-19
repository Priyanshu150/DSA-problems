#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*n + n*log(n))
// Space complexity :- O(n)

// Approach :-  
// fact -> Inorder of the BST is sorted 
// We will find the inorder of the traversal of the given BST
// sort the inorder and now place this sorted inorder in the BST 


// Link :- https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    void inorder1(Node* nd, vector<int> &nodes){
        if(!nd)     return;
        
        inorder1(nd -> left, nodes);
        nodes.push_back(nd -> data);
        inorder1(nd -> right, nodes);
    }
    
    void inorder2(Node* nd, vector<int> &nodes, int &ind){
        if(!nd)     return;
        
        inorder2(nd -> left, nodes, ind);
        nd -> data = nodes[ind++];
        inorder2(nd -> right, nodes, ind);
    }
  
  public:
    void correctBST(Node* root) {
        // add code here.
        int ind = 0;
        vector<int> nodes;
        inorder1(root, nodes);
        sort(nodes.begin(), nodes.end());
        inorder2(root, nodes, ind);
    }
};