#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Traverse on each node of the tree
// hash each node's value in either map, set
// find the new_target which will be (target - root->data)
// Find this new target in map if present that means the pair exist in the map

// Link :- https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

class Node {
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
    unordered_set<int> st;
  
  public:
    bool findTarget(Node *root, int target) {
        // your code here.
        if(!root)       return false;
        
        bool lt = findTarget(root -> left, target);
        
        int newTarget = target - root->data;
        if(st.count(newTarget))
            return true;
        
        st.insert(root -> data);
        
        bool rt = findTarget(root -> right, target);
        
        return (lt || rt);
    }
};