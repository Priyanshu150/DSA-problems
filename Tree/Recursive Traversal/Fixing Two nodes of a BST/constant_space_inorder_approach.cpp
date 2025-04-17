#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// fact -> Inorder of the BST is sorted 
// There can two case :-
// 1. Values that has to be swapped are adjacent 
// 2. Values that have to be swapped are not adjacent
// We maintain three pointer (first, middle, last) while traversing the array / tree
//  If we find the first violation of sorting we'll store currnode in middle and prevNode in first
// If we found second violation of sorting then we'll store currnode in last
// 1. If we don't find the second violation that means swapping first and middle will sort the sequence
// 2. If we got the second violation that means sort first and last node will sort the sequence


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
    Node* first, *second, *middle, *prev;
    
    void inorder(Node *node){
        if(!node)       return;
        
        inorder(node -> left);
        if(prev && prev -> data > node -> data){
            if(first != nullptr)
                second = node;
            else{
                first = prev;
                middle = node;
            }
        }
        prev = node;
        inorder(node -> right);
    }
    
  public:
    void correctBST(Node* root) {
        // add code here.
        first = second = middle = prev = NULL;
        inorder(root);
        
        int temp = first -> data;
        if(second == nullptr){
            first -> data = middle -> data;
            middle -> data = temp;
            return;
        }
        first -> data = second -> data;
        second -> data = temp;
    }
};

