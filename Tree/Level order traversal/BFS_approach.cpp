#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Perform breath first search approach and stores nodes present on each level 


//Link :- https://www.geeksforgeeks.org/problems/level-order-traversal/1

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> ans;
        queue<Node*> q;
          
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> nodes;
            
            while(sz--){
                Node* nd = q.front();
                q.pop();
                
                nodes.push_back(nd->data);
                if(nd->left)    q.push(nd->left);
                if(nd->right)   q.push(nd->right);
            }
            ans.push_back(nodes);
        }
        return ans;
    }
};