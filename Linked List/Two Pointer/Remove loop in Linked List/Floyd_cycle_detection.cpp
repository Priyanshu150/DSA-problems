#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// Use floyd cycle detection method, fast and slow pointer which will meet at certain point
// they will meet because fast moves by 2 and slow moves by 1
// eventually every time the distance b/w them will reduce by 1 and will become 0

// If the whole list is a cycle then slow and fast will be pointing to head
// move slow until slow -> next == head and then eventually make slow -> next = nullptr

// Otherwise initialise fast = head and move slow and fast until slow -> next == fast -> next
// then slow -> next = null 

//Link :- https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

struct Node{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node *fast = head, *slow = head;
        
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(fast == slow){
                fast = head;
                bool flag = true;
                
                if(slow == head){
                    while(slow -> next != head)
                        slow = slow -> next;
                    
                    flag = false;
                }
                    
                while(flag && fast -> next != slow -> next){
                    fast = fast -> next;
                    slow = slow -> next;
                }
                slow -> next = nullptr;
                return;
            }
        }
        return;
    }
};