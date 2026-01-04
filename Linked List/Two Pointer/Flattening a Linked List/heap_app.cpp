#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*m*log(n))
//Space complexity :- O(n)

// Approach :-
// create a heap and add the data into form of pair into it {val, address}
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

class Solution {
  private:
    typedef pair<int, Node*> pin;
  
  public:
    Node *flatten(Node *root) {
        priority_queue<pin, vector<pin>, greater<pin> > pq;
        Node* temp = root;
        
        // add all the list into priority queue
        while(temp){
            Node* ahead = temp -> next;     // save the next ptr 
            temp -> next = nullptr;         // next pointer assign it to null
            pq.push({temp -> data, temp});  // add the node with value into pq
            temp = ahead;                   // move to the next list 
        }
        
        Node *newHead = new Node(-1), *tail = newHead;
        
        while(!pq.empty()){
            // extract the top-most node from the queue 
            Node* curr = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            
            // update the address of the links 
            tail -> bottom = curr;
            tail = tail -> bottom;
            
            // if next node exist add them into the queue
            if(curr -> bottom) {
                curr = curr -> bottom;
                pq.push({curr -> data, curr});
            }
        }
        // delete the first dummy node having value -1 
        Node* toDelete = newHead;
        newHead = newHead -> bottom;
        delete(toDelete);
        
        return newHead;
    }
};