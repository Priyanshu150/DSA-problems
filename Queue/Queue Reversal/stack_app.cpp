#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// use stack to store the elements of the queue it'll reverse the automatically reverse the elements 


// links :- https://www.geeksforgeeks.org/problems/queue-reversal/1

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int> st;
        
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            
            st.push(ele);
        }
        
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            
            q.push(ele);
        }
    }
};