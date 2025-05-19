#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// Inorder of the BST is sorted so we'll traverse the tree using inorder
// and we'll store the value of before and after the key which will be our successor and predecessor 


//Link :- https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

class Solution {
  private:
    Node *pred, *succ;
    
    void solve(Node* root, int &key){
        if(!root)
            return;
        
        solve(root -> left, key);
        
        if(root -> data < key)
            pred = root;
        
        if(!succ && root -> data > key)
            succ = root;
            
        solve(root -> right, key);
    }

  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        pred = succ = nullptr;
        solve(root, key);
        return {pred, succ};
    }
};