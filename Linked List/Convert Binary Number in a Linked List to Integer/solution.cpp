#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

//Approach :- 
// traverse on the list and genate the number based on the bit 

//Link :- https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode *temp = head;

        while(temp){
            res = (res<<1) + temp->val;
            temp = temp -> next;
        }
        return res;
    }
};

// Approach 2
class Solution {
private:
    int length(ListNode* head){
        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp = temp -> next;
        }
        return len;
    }

public:
    int getDecimalValue(ListNode* head) {
        int size = length(head)-1;
        ListNode* temp = head;
        int res = 0;

        while(temp){
            if(temp -> val == 1){
                res += (1<<size);
            }
            size--;
            temp = temp -> next;
        }
        return res;
    }
};