#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))  -- n is total number of nodes 
// Space complexity :- O(m)    -- m is number of list 

// Approach :- 
// Use a minHeap and push all the list nodes head 
// using min node on the top build a list which is sorted 

// Link :- https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

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
    #define pin pair<int, Node*>
  
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<pin, vector<pin>, greater<pin> > pq;
        
        for(Node* node: arr){
            pq.push({node -> data, node});
        }
        Node* newHead = new Node(-1), *temp = newHead;
        
        while(!pq.empty()){
            int val = pq.top().first;
            Node* node = pq.top().second;
            pq.pop();
            
            temp -> next = node;
            temp = temp -> next;
            
            if(node -> next){
                pq.push({node -> next -> data, node -> next});
            }
        }
        Node* toDelete = newHead;
        newHead = newHead -> next;
        delete(toDelete);
        
        return newHead;
    }
};