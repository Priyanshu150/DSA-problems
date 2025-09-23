#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)
// Space complexity :- O(N)

// Approach :-
// Using single stack we have to store 2 number at the same place 
// modulo operator can be used to implement the same
// formula :- max_limit * a + b
// max_limit can be max number that can be inserted in the stack + 1
// a is the original number 
// b is the min number till now
// to get orignal number we can use the formula (st.top() / max_limit)
// to get the min number we can use the formula (st.top() % max_limit)


// Link :- https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

class Solution {
  private:
    #define ll long long
  
    ll limit;
    stack<ll> st;
  
  public:
    Solution() {
        // code here
        limit = 1e9+1;
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        ll newNum = 0;
        
        if(st.empty())      newNum = limit*x + (ll)x;
        else        newNum = limit*x + min<ll>(x, st.top() % limit);
        
        st.push(newNum);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty())
            return;
        
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty())
            return -1;
        
        return (int)(st.top() / limit);
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty())
            return -1;
        
        return (int)(st.top() % limit);
    }
};