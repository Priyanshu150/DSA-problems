#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*n*m)
//Space complexity :- O(n)

// Approach :-
// use recursion to flaten the next list 
// and merge two list using bottom pointer 

//link :- https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  private:
    Node* mergeSortedList(Node* list1, Node* list2){
        // base cases 
        if(!list1)      return list2;
        if(!list2)      return list1;
        
        Node *newHead = new Node(-1), *ptr = newHead;
        Node *ptr1 = list1, *ptr2 = list2; 
        
        // reset bottom the list next pointer 
        ptr1 -> next = nullptr;
        ptr2 -> next = nullptr;
        
        // both list exists then try to merge them based on ascending order 
        while(ptr1 && ptr2){
            if(ptr1 -> data <= ptr2 -> data){
                ptr -> bottom = ptr1;
                ptr1 = ptr1 -> bottom;
            }else{
                ptr -> bottom = ptr2;
                ptr2 = ptr2 -> bottom;
            }
            ptr = ptr -> bottom;
        }
        // list2 is exhausted and list1 still remains 
        if(ptr1){
            ptr -> bottom = ptr1;
            ptr = ptr -> bottom;
        }
        // list1 is exhausted and list2 still remains 
        else{
            ptr -> bottom = ptr2;
            ptr = ptr -> bottom;
        }
        
        // update the links and delete the extra nodes 
        Node* toDelete = newHead;
        newHead = newHead -> bottom;
        delete(toDelete);
        
        return newHead;
    }
  
  public:
    Node *flatten(Node *root) {
        if(!root || !root->next)
            return root;
        
        // recur for next list 
        root -> next = flatten(root -> next);
        
        // now merge the current and next list
        root = mergeSortedList(root, root->next);
        return root;
    }
};