#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// use min heap to keep all the head pointer along with it data in it
// the lowest value data will be on top extract that out and start making new list
// point the curr pointer to the next pointer of the list and then put it into the list 
// repeat this until the queue is empty and stop pushing node if next pointer is null 

// Link :- https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class Solution {
  private:
    #define pii pair<int, Node*> 
  
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        
        for(auto nd: arr)
            pq.push({nd->data, nd});
        
        Node* head = nullptr, *temp = nullptr;
        
        while(!pq.empty()){
            int data = pq.top().first;
            Node* nd = pq.top().second;
            pq.pop();
            
            if(head)        temp -> next = nd;
            else            head = nd;
            
            temp = nd;
            nd = nd -> next;
            if(nd)      pq.push({nd -> data, nd});
        }
        return head;
    }
};