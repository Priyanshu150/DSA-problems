#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

//Approach :- 
// Take 3 pointers and assign current, previous and next links to it
// change the pointer accordingly

//Link :- https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

struct Node
{
    int data;
    struct Node *next;
};

class Solution{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* prev=NULL;
        Node* curr=head;
        Node* next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
};