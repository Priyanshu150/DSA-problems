#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

//Approach :- 
// Apply fast and slow pointer, the two pointer approach
// If they meet at any point that menas loop exits
// Otherwise not


//Link :- https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

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
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        Node* slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow -> next; 
            fast = fast -> next -> next;
            
            if(slow == fast)
                return true;
        }
        return false;
    }
};