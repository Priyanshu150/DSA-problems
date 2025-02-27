#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)
// Space complexity :- O(N + N)

// Approach :-
// Use two stack to track the element and min_element
// In 1st stack, keep the original element as it is 
// In 2nd stack, keep the min element till now in the stack


// Link :- https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

class Solution {
  private:
    stack<int> s1, s2;
  
  public:
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        s1.push(x);
        if(s2.empty())  s2.push(x);
        else    s2.push(min(x, s2.top()));
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(s1.empty())
            return;
        
        s1.pop();
        s2.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(s1.empty())
            return -1;
            
        return s1.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(s1.empty())
            return -1;
            
        return s2.top();
    }
};