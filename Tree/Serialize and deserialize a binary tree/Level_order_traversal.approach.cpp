#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// While serialising, we'll save the level order traversal of the tree into the array and for null node we'll put -1
// While de-serialising, we should traverse the array one at a time
// Node at index 0 will be root, which we put in queue
// we take each node once at a time from the queue and traverse array one at a time
// If we found a positive value then we create a node and assign repective pointer to repective node pointer
// if we found negative value i.e. -1 that means it a nullptr

// Link :- https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> arr;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node *nd = q.front();
            q.pop();
            
            if(!nd){
                arr.push_back(-1);
                continue;
            }
            arr.push_back(nd -> data);
            q.push(nd->left);
            q.push(nd->right);
        }
        return arr;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        int n = arr.size(), ind = 1;
        Node* root = new Node(arr[0]);
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(arr[ind] == -1)
                node -> left = nullptr;
            else{
                Node *newNode = new Node(arr[ind]);
                node -> left = newNode;
                q.push(newNode);
            }
            ++ind;
            
            if(arr[ind] == -1)
                node -> right = nullptr;
            else{
                Node *newNode = new Node(arr[ind]);
                node -> right = newNode;
                q.push(newNode);
            }
            ++ind;
        }
        return root;
    }
};