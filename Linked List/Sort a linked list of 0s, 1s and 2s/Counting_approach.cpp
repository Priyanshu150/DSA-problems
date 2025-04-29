#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// Count the occurence of ones, zeros during first traversal of the list 
// again traverse on the list and put 0 the number of times zero was present
// similarly repeat for 1 and rest all the left will be zeros 

//link :- https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // code here
        int zeros = 0, ones = 0;
        Node* temp = head;
        
        while(temp){
            if(temp -> data == 0)
                zeros++;
            else if(temp -> data == 1)
                ones++;
            
            temp = temp -> next;
        }
        temp = head;
        
        while(temp){
            if(zeros){
                temp -> data = 0;
                zeros--;
            }
            else if(ones){
                temp -> data = 1;
                ones--;
            }
            else{
                temp -> data = 2;
            }
            temp = temp -> next;
        }
        return head;
    }
};