#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// we'll use morris traversal to traverse the tree as it uses constant space 
// first find the number of nodes in the tree 
// then find the node number which we've to find using given formula
// traverse the tree and create inorder because inorder of BST is always sorted 
// start counting for each node when we find our target node then return the answer 


// links :- https://www.geeksforgeeks.org/problems/median-of-bst/1

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  private:
    int countOfNodes(Node* root){
        int cnt = 0;
        Node* curr = root;
        
        while(curr){
            // if no left subtree exist 
            if(curr -> left == nullptr){
                cnt++;
                curr = curr -> right;
            }else{
                Node* prev = curr -> left;
                // go to extreme right child of left subtree 
                while(prev -> right && prev -> right != curr)
                    prev = prev -> right;
                
                // left subtree un-explored 
                if(prev -> right == nullptr){
                    prev -> right = curr;
                    curr = curr -> left;
                }
                // explore right subtree
                else{
                    prev -> right = nullptr;
                    cnt++;
                    curr = curr -> right;
                }
            }
        }
        return cnt;
    }
  
  public:
    int findMedian(Node* root) {
        // Code here
        int total = countOfNodes(root);
        int ind = (total+1)/2, cnt = 0;
        
        Node *curr = root;
        
        while(curr){
            // no-left subtree
            if(curr -> left == nullptr){
                cnt++;
                if(cnt == ind)
                    return curr -> data;
                
                curr = curr -> right;
            }else{
                Node* prev = curr -> left;
                // find the extreme right node of left-subtree
                while(prev -> right && prev -> right != curr)
                    prev = prev -> right;
                
                // left-subtree un-explored 
                if(prev -> right == nullptr){
                    prev -> right = curr;
                    curr = curr -> left;
                }
                // explore right subtree 
                else{
                    //reset the link
                    prev -> right = nullptr; 
                    cnt++;
                    if(cnt == ind)
                        return curr -> data;
                    curr = curr -> right;
                }
            }
        }
        return -1;
    }
};