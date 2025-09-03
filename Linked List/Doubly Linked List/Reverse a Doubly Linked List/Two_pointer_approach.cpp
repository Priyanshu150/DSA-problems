#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// use 3 pointer store the link of prev, curr and next linked list 
// and change the link so that the list becomes reversed 

//Link :-  https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* prev = nullptr, *curr = head, *ahead;
        
        while(curr){
            ahead = curr -> next;
            curr -> prev = ahead;
            curr -> next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
};