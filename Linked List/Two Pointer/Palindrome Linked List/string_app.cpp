#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-  
// form a string using the data of the list 
// and check if the strig is palindrom or not 

//link :- https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    bool palindrome(string test){
        int i=0;
        int j=test.length()-1;
        
        while(i<j){
            if(test[i]!=test[j])
                return false;
            i++;
            j--;
        }
        return true;
        
    }


    bool isPalindrome(Node *head){
        Node* temp=head;
        string val=""; 
        
        // conver the list to string using the list values 
        while(temp!=NULL){
            val+=temp->data;
            temp=temp->next;
        }
        
        // check if the string is palindrom or not 
        if(palindrome(val))
            return true;
        else
            return false;
    }
};

