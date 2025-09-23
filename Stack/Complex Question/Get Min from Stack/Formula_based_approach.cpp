#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)
// Space complexity :- O(N)

// Approach :-
// we can use a stack and minEle variable to solve this problem
// We can use mathematically derived formula (2*val - minEle) while push
// and minEle = (2*minEle) - top_element
// these formula are applied only when they incoming val or top element is smaller

// Link :- https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

class Solution {
  private:
    int minEle;
    stack<int> st;
  
  public:
    Solution() {
        // code here
        minEle = INT_MAX;
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(st.empty()){
            st.push(x);
            minEle = x;
        }
        else if(minEle <= x)
            st.push(x);
        else{
            st.push(2*x - minEle);
            minEle = x;
        }
            
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty())
            return;
        
        int y = st.top();
        st.pop();
        
        if(y < minEle)      minEle = 2*minEle - y;
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty())
            return -1;
        
        int ele = st.top();
        if(minEle < ele)    return ele;
        
        return minEle;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty())
            return -1;
        
        return minEle;
    }
};