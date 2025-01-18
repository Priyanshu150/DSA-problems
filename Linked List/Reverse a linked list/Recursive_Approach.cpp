#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

//Approach :- 
// Solve one smaller case and rest recursion can handle 
// Store the newhead value and return the same

//Link :- https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

struct Node
{
    int data;
    struct Node *next;
};

class Solution {
  private:
    Node* newHead;
    
    Node* reverse(struct Node* node){
        if(!node)       return NULL;
        if(!node->next){
            newHead = node;
            return node;
        }
        Node* tail = reverse(node -> next);
        tail -> next = node;
        node -> next = nullptr;
        return node;
    }
  
  public:
    Node* reverseList(struct Node* head) {
        // code here
        newHead = nullptr;
        reverse(head);
        return newHead;
    }
};