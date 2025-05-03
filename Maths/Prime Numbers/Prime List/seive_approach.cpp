#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))  
// Space complexity :- O(1)

// Approach :-
// Using seive calculate the number which are prime for the value till 1e5
// traverse on the list for every number in the node 
// find the left and right smallest prime number and update the answer
// Traversing left and right will be way smaller as finding prime will be as good as constant operation

// Link :- https://www.geeksforgeeks.org/problems/prime-list--170646/1


class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

class Solution {
  private:
    const int maxValue = 1e5+2;
    vector<bool> dp;
    
    void seive(){
        dp.resize(maxValue, true);
        
        for(int i=2; i*i<=maxValue; ++i){
            if(dp[i]){
                for(int j=i*i; j<=maxValue; j+=i){
                    dp[j] = false;
                }
            }
        }
    }
  
  public:
    Node *primeList(Node *head) {
        // calculate the prime number using seive 
        seive();
        Node* temp = head;
        
        // traverse on the list 
        while(temp){
            int num = temp -> val, left = num, right = num;
            // Go on to the left and right of number to find the nearest number which is prime
            while(true){
                if(left>1 && dp[left]){
                    temp -> val = left;
                    break;
                }
                if(right>1 && right<maxValue && dp[right]){
                    temp -> val = right;
                    break;
                }
                --left;
                ++right;
            }
            temp = temp -> next;
        }
        return head;
    }
};
