#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N+N)       
//Space complexity :- O(N)    

// Approach :-
// we use single traversal of the element for optimized approach
// the previous_greater_element can be calculate like we were doing previously traversing from left to right
// for next_greater_element if any length is getting poped by current_length that me it's right boundary is current element 
// the logic remains to calculate are will be (nge - pge - 1)*arr[i]
// At last if some element are present in the stack calculate the area using same formula by considering nge as n


//link :- https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        stack<int> st;
        int n = arr.size(), res = 0;
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && arr[i] < arr[st.top()]){
                int length = arr[st.top()];
                st.pop();
                int nge = i, pge = st.empty() ? -1 : st.top();
                
                res = max(res, (nge - pge - 1)*length);
            }
            st.push(i);
        }
        while(!st.empty()){
            int length = arr[st.top()];
            st.pop();
            int nge = n, pge = st.empty() ? -1 : st.top();
            
            res = max(res, (nge - pge - 1)*length);
        }
        return res;
    }
};