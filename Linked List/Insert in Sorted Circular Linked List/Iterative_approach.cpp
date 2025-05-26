#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// There will be 3 case to insert a node in the list :- First, last and middle 
// if we've to insert at first, then find the last node of list and change the the links 
// if we've to insert at last, then traverse the node till last node and change the links so that it remains circular list 
// if we've to insert at middle, then find the node whose next node's data is greater than value to be inserted
// then accordingly change the links of the node respectively


// Link :- https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; 

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newNode = new Node(data), *temp = head;
        
        if(head -> data >= data){
            while(temp -> next != head){
                temp = temp -> next;
            }
            newNode -> next = head;
            temp -> next = newNode;
            return newNode;
        }
        
        while(temp -> next != head){
            if(temp -> next -> data >= data){
                break;
            }
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
        return head;
    }
};