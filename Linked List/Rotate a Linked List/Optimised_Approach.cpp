#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*N)
// Space complexity :- O(1)

//Approach :- 
// Find the length of the list and take k=(k%len) 
// If k==0 then no need to rotate
// Traverse to the list and make some link changes to find the rotated list 

//Link :- https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    int length(Node* head){
        int len = 0;
        Node* temp = head;
        
        while(temp){
            len++;
            temp = temp -> next;
        }
        return len;
    }
  
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        int len = length(head), ind = 0;
        k %= len;
        if(k == 0)      return head;
        
        Node* temp = head, *tail = nullptr, *newHead = nullptr, *newTail = nullptr;
        
        while(temp){
            if(ind == k-1)
                newTail = temp;
            if(ind == k)
                newHead = temp;
                
            ind++;
            tail = temp;
            temp = temp->next;
        }
        tail -> next = head;
        newTail -> next = nullptr;
        return newHead;
    }
};