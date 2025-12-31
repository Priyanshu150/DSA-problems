#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-  
// traverse on the list and find the middle of list using fast and slow pointer 
// seprate the list from the middle and reverse it 
// match both the list if they are matching mean it's a palindrome otherwise it's not 
// restore the previous list 


//link :- https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

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
  private:
    Node* reverse(Node* head){
        Node *curr = head, *prev = nullptr, *ahead;
        
        // current node is still present 
        while(curr != nullptr){
            // point current node to previous and save the next node link
            ahead = curr -> next;
            curr -> next = prev;
            
            // update current and next pointer 
            prev = curr; 
            curr = ahead;
        }
        return prev;
    }
    
    bool isIdentical(Node* n1, Node* n2){
        // traverse on the both nodes 
        for(;n1 && n2; n1 = n1->next, n2 = n2->next){
            // if they differ in value that means they are not identical
            if(n1 -> data != n2 -> data)
                return false;
        }
        return true;
    }
  
  public:
    bool isPalindrome(Node *head) {
        // only 1 nodes in list 
        if(!head -> next)
            return true;
        
        Node* slow = head, *fast = head;
        
        // move slow ptr to the middle of linked list 
        while(fast -> next && fast -> next -> next){
            slow = slow -> next; 
            fast = fast -> next -> next;
        }
        // split the list and reverse the second half 
        Node *head2 = reverse(slow -> next);
        // end the second half 
        slow -> next = nullptr; 
        
        // check if two halfs are identical 
        bool res = isIdentical(head, head2);
        
        // restore the original list 
        head2 = reverse(head2);
        slow -> next = head2;
        
        return res;
    }
};