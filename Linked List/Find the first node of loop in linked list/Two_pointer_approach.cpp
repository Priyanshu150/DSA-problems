#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*N)
// Space complexity :- O(1)

//Approach :- 
// find wheather a loop exist or not using fast and slow pointer
// If loop doesn't exist then return nullptr
// Otherwise point one of the node from fast or slow to head
// And move them until they meet on the same node, return the same node


//Link :- https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

struct Node{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        Node* slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast)
                break;
        }
        if(!fast || !fast->next)        return nullptr;
        
        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
        
    }
};