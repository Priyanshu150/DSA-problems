#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*log(k))
//Space complexity :- O(k)

// Approach :-
// create a cutom heap and add the  {address} into the heap
// sort the heap based on the value of nodes 
// using the queue build a new sorted list 


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

struct comp{
    bool operator()(Node *l1, Node *l2){
        return (l1 -> data > l2 -> data);
    }
};

class Solution {
  public:
    Node *flatten(Node *root) {
        priority_queue<Node*, vector<Node*>, comp> pq;
        Node* temp = root;
        
        // add all the list into priority queue
        while(temp){
            Node* ahead = temp -> next;     // save the next ptr 
            temp -> next = nullptr;         // next pointer assign it to null
            pq.push(temp);                  // add the node into pq
            temp = ahead;                   // move to the next list 
        }
        
        Node *newHead = new Node(-1), *tail = newHead;
        
        while(!pq.empty()){
            // extract the top-most node from the queue 
            Node* curr = pq.top();
            pq.pop();
            
            // update the address of the links 
            tail -> bottom = curr;
            tail = tail -> bottom;
            
            // if next node exist add them into the queue
            if(curr -> bottom) {
                pq.push(curr -> bottom);
            }
        }
        // delete the first dummy node having value -1 
        Node* toDelete = newHead;
        newHead = newHead -> bottom;
        delete(toDelete);
        
        return newHead;
    }
};