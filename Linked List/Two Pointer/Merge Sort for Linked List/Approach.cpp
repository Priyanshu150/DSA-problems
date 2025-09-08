#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(log n) (recursive stack), otherwise O(1) extra.

// Approach :- 
// Using same concept of merge sort which we use in array's 
// for spliting into two halves we use two pointer(fast & slow ) approach
// Again for merge two list we can use merge two sorted list approach 

// Link :- https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    Node* findMiddle(Node* head){
        Node* slow = head, *fast = head -> next;
        
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    Node* merge(Node* left, Node* right){
        Node* newHead = new Node(-1), *temp = newHead;
        Node* temp1 = left, *temp2 = right;
        
        while(temp1 && temp2){
            if(temp1 -> data <= temp2 -> data){
                temp -> next = temp1;
                temp = temp1;
                temp1 = temp1 -> next;
            }
            else{
                temp -> next = temp2;
                temp = temp2;
                temp2 = temp2 -> next;
            }
        }
        if(temp1)
            temp -> next = temp1;
        else 
            temp -> next = temp2;
        
        Node* toDelete = newHead;
        newHead = newHead -> next;
        delete(toDelete);
        return newHead;
    }
  
  public:
    Node* mergeSort(Node* head) {
        // code here
        if(!head || !head->next)
            return head;
        
        Node* middle = findMiddle(head);
        Node* newHead = middle -> next;
        middle -> next = nullptr;
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(newHead);
        return merge(left, right);
    }
};