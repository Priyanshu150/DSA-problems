#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N + M)
// Space complexity :- O(1)

//Approach :- 
// Traverse the both list from last and add the numbers 
// Forward the carry as we do in addition 
// Repeat this as long as list exists
// Reverse the ans list
// Finally delete all the number which are zeros in front

//Link :- https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    Node* reverse(Node* head){
        Node* prev = NULL, *curr = head;
        
        while(curr){
            Node* ahead = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
  
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node *temp1 = num1, *temp2 = num2;
        
        while(temp1 && temp1->data == 0)
            temp1 = temp1->next;
        
        while(temp2 && temp2->data == 0)
            temp2 = temp2->next;
        
        temp1 = reverse(temp1);
        temp2 = reverse(temp2);
        
        int carry = 0;
        Node* newHead = new Node(-1), *dummy = newHead;
        
        while(temp1 || temp2 || carry){
            int sum = carry;
            if(temp1)   sum += temp1 -> data;
            if(temp2)   sum += temp2 -> data;
            
            Node* newNode = new Node(sum%10);
            if(sum > 9)     carry = 1;
            else            carry = 0;
            
            dummy->next = newNode;
            dummy = newNode;
            if(temp1)   temp1 = temp1->next;
            if(temp2)   temp2 = temp2->next;
        }
        newHead = reverse(newHead->next);
        while(newHead && newHead->data == 0)
            newHead = newHead->next;
        
        if(newHead == NULL)     return new Node(0);
        return newHead;
    }
};