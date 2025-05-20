#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :- 
// Traversing the tree make a marking for child to parent and also store the node address of target
// Apply the BFS traversal from the tree node which is burned 
// and calulate the time based on the level order traversal

// Link :- https://www.geeksforgeeks.org/problems/burning-tree/1

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
    unordered_map<Node*, Node*> parent;
    
    void markParent(Node* root, Node* par, Node* &trgt, int &target){
        if(!root)       return;
        if(root -> data == target)
            trgt = root;
        
        parent[root] = par;
        markParent(root -> left, root, trgt, target);
        markParent(root -> right, root, trgt, target);
    }
  
  public:
    int minTime(Node* root, int target){
        // Your code goes here
        Node* trgt = NULL;
        markParent(root, NULL, trgt, target);
        
        int level = 0;
        queue<Node*> q;
        unordered_set<Node*> vis;
        
        q.push(trgt);
        vis.insert(trgt);
        
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                Node* nd = q.front();
                q.pop();
                
                if(nd -> left && !vis.count(nd->left)){
                    q.push(nd -> left);
                    vis.insert(nd -> left);
                }
                if(nd -> right && !vis.count(nd -> right)){
                    q.push(nd -> right);
                    vis.insert(nd -> right);
                }
                if(parent[nd] && !vis.count(parent[nd])){
                    q.push(parent[nd]);
                    vis.insert(parent[nd]);
                }
            }
            ++level;
        }
        return level-1;
    }
};