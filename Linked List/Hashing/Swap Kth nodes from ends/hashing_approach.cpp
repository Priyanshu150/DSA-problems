#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :- 
// In map store the index and address of each node 
// After that swap the data of nodes using address stored in map 


//Link :-  https://www.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        int cnt = 0;
        Node* temp = head;
        unordered_map<int, Node*> mp;
        
        while(temp){
            cnt++;
            mp[cnt] = temp;
            temp = temp -> next;
        }
        if(k > cnt)     return head;
        
        int val = mp[k]->data;
        mp[k] -> data = mp[cnt+1-k] -> data;
        mp[cnt+1-k] -> data = val;
        return head;
    }
};