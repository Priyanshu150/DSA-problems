#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k)
//Space complexity :- O(k)

// Approach :-
// for flatening the list we can select 2 list at at time 
// and merge them using bottom pointer
// finally return the merge head as our final list 

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
        while(ptr1){
            ptr -> bottom = ptr1;
            ptr1 = ptr1 -> bottom;
            ptr = ptr -> bottom;
        }
        // list1 is exhausted and list2 still remains 
        while(ptr2){
            ptr -> bottom = ptr2;
            ptr2 = ptr2 -> bottom;
            ptr = ptr -> bottom;
        }
        // reset the last bottom node 
        ptr -> bottom = nullptr;
        
        // update the links and delete the extra nodes 
        Node* toDelete = newHead;
        newHead = newHead -> bottom;
        delete(toDelete);
        
        return newHead;
    }
  
  public:
    Node *flatten(Node *root) {
        if(!root)
            return root;
        
        Node* curr = root;
        
        // until next ptr exist we'll flaten the list 
        while(curr -> next){
            // save the next ptr 
            Node* ahead = curr -> next -> next;
            // merge the curr and next list 
            curr = mergeSortedList(curr, curr -> next);
            // update the link for both
            curr -> next = ahead;
        }
        return curr;
    }
};