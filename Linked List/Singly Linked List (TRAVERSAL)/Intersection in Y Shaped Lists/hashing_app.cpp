#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :- 
// Hash the nodes address from one list
// traverse on the second list and first node which exist in the hash set will be our answer 


// Link :- https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        unordered_set<Node*> nodes;
        
        Node *temp = head1;
        
        while(temp){
            nodes.insert(temp);
            temp = temp -> next;
        }
        temp = head2;
        
        while(temp){
            if(nodes.count(temp))
                return temp -> data;
            
            temp = temp -> next;
        }
        return -1;
    }
};