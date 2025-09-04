#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// Traverse on the list and reverse the first k or length nodes 
// using recursion reverse the rest of the links 
// and finally merge the links to form the final list

// Link :- https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

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
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head || !head->next)
            return head;
        
        int cnt = 0;
        Node* prev = nullptr, *curr = head, *ahead;
        
        while(curr && cnt < k){
            ahead = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = ahead;
            cnt++;
        }
        head -> next = reverseKGroup(curr, k);
        return prev;
    }
};