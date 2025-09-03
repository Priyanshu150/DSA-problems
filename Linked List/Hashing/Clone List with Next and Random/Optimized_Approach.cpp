#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

//Approach :- 
// For creating a copy of original list with random pointer we need to follow these steps
// First step,
// create a duplicate node for every node an assign it to next of the node in original list 
// Ex- 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> x, where node' represent duplicate node

// Second step, Assign the random pointers
// Random pointer of duplicate node will be next pointer of the random pointer of original list 
// temp -> next -> random = temp -> random -> next;

// Third step, 
// Segregrate both the copy list and original list


//Link :- https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node* temp = head;
        
        //Creation of new nodes of copy list
        while(temp){
            Node* nex = temp -> next;
            Node* newNode = new Node(temp -> data);
            
            temp -> next = newNode;
            newNode -> next = nex;
            
            temp = nex;
        }
        // Assigning random values to copy list 
        temp = head;
        while(temp){
            if(temp -> random)
                temp -> next -> random = temp -> random -> next;
            else
                temp -> next -> random = nullptr;
            
            temp = temp -> next -> next;
        }
        // Seprate original list and copy list from each other 
        Node* copyListHead = head -> next, *dummy = copyListHead;
        temp = head;
        
        while(temp){
            if(temp -> next != dummy){
                dummy -> next = temp -> next;
                dummy = dummy -> next;
            }
            temp -> next = temp -> next -> next;
            temp = temp -> next;
        }
        return copyListHead;
    }
};
