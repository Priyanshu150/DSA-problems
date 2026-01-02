#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// traverse two list simultaneously using two pointer 
// when one pointer hits the nullptr it's reassigned to head 
// traverse until we reach the insertion point of the list 

// Link :- https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if(head1 == nullptr || head2 == nullptr)
            return nullptr;
        
        Node* temp1 = head1, *temp2 = head2;
        
        // traverse through the list until the pointers meet 
        while(temp1 != temp2){
            // move to the next node in each list and if the one 
      	    // pointer reaches NULL, start from the other linked list
            temp1 = temp1 ? temp1 -> next : head1;
            temp2 = temp2 ? temp2 -> next : head2;
        }
        return temp1;
    }
};


// approach-2

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node* temp1 = head1, *temp2 = head2;
        
        // traverse both list parallely untill one exhausts 
        while(temp1 && temp2){
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        Node* temp = nullptr;
        
        // exhauts the other list 
        if(temp1 == nullptr){
            temp = head2;
            
            while(temp2){
                temp2 = temp2 -> next;
                temp = temp -> next;
            }
            // reassign the links 
            temp1 = head1, temp2 = temp;
        }else{
            temp = head1;
            
            while(temp1){
                temp1 = temp1 -> next;
                temp = temp -> next;
            }
            
            // reassign the links 
            temp2 = head2, temp1 = temp;
        }
        
        // traverse on the both list 
        do{
            // current node is same in both 
            if(temp1 == temp2)
                return temp1;
            
            
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
            
        }while(temp1 && temp2);
        
        return nullptr;
    }
};