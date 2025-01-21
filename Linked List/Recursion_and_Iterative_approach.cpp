#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N/K)

//Approach :- 
// Reverse first K ele or rest(if it's node are less in number than k) of the element of list 
// Use recursion to call rest of the after
// Attach the tail to the node return by recursion 

//Link :- https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

//   Node is defined as
    struct Node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    };

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head || !head->next)   
            return head;
            
        Node *prev = NULL, *curr = head, *nex;
        
        for(int i=0; i<k && curr; ++i){
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }
        Node* node = reverseKGroup(curr, k);
        head -> next = node;
        return prev;
    }
};