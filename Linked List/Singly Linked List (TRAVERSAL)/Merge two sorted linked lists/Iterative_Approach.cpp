#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(min(N, M))
// Space complexity :- O(1)

//Approach :- 
//Traverse both array parrallely and make the new sorted list 
// Initialise a newHead and dummy value 
// assign dummy's next pointer to lower value from both list 
// move dummy, ptr1 and ptr2 accordingly

//Link :- https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1


struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* newHead = new Node(-1), *dummy = newHead;
        Node *temp1 = head1, *temp2 = head2;
        
        while(temp1 && temp2){
            if(temp1 -> data <= temp2 -> data){
                dummy -> next = temp1;
                temp1 = temp1 -> next;
            }
            else{
                dummy -> next = temp2;
                temp2 = temp2 -> next;
            }
            dummy = dummy -> next;
        }
        if(temp1)   dummy -> next = temp1;
        if(temp2)   dummy -> next = temp2;
        
        dummy = newHead;
        newHead = newHead -> next;
        dummy -> next = nullptr;
        delete(dummy);
        return newHead;
    }
};