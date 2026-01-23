#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-  
// using stack and nge/pge concept find the index of the eleement 
// which is greater than or equal to current element on both side 
// number of people current person can see will be (right - left - 1)
// -1 because current person was counted twice 

// links :- https://www.geeksforgeeks.org/problems/maximum-people-visible-in-a-line/1

class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size(), res = 0;
        stack<int> st;
        vector<int> right(n, 0);
        
        // traverse from right to left 
        for(int i=n-1; i>=0; --i){
            // maintain a increasing monotonic stack 
            while(!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            
            // update the number of people can be seen by current people 
            if(st.empty())      right[i] = (n - i);
            else                right[i] = (st.top() - i);
            
            st.push(i);     // add the index to the stack 
        }
        // empty the stack 
        while(!st.empty()){
            st.pop();
        }
        // traverse from left to right
        for(int i=0; i<n; ++i){
            // maintain a monotonic stack of increasig order 
            while(!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            
            int canSee = 0;
            // update the number of people can be seen by current people 
            if(st.empty())      canSee = right[i] + (i + 1);
            else                canSee = right[i] + (i - st.top());
            
            // update the max anwer based on previous and current calculations
            res = max(res, canSee-1);
            
            st.push(i);     // add index to the stack 
        }
        return res;
    }
};