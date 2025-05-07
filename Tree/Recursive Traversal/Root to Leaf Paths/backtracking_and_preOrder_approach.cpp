#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :-
// we'll use preorder traversal to traverse the tree and maintain a array in which we push the nodes
// while visiting the nodes we'll add them into the array 
// and then traverse the left and right subtree of that tree
// after coming back we can backtrack and hence making current node removed from the path
// for base case, when we're at the left node we'll add that array into our answer
// if the node is null then return from that point


// Link :- https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  private:
    vector<vector<int>> ans;
    
    void solve(Node* node, vector<int> &temp){
        if(!node)
            return;
            
        temp.push_back(node -> data);
        
        if(!node->left && !node->right){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        solve(node -> left, temp);
        solve(node -> right, temp);
        temp.pop_back();
    }
  
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> temp;
        solve(root, temp);
        return ans;
    }
};