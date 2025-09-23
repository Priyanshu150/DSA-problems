#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-  
// Using the logice of next greater element, we'll use the stack 
// since the array is circular, for (n-1)th element the element greater than it can be at (n-2)th element
// we'll start traversing the from ind = n+n-2 index untill index is not negative 
// maintaining a monotonic stack which tell which is the element greater than current element on the right
// we'll start accumulating our answer when ind become less than n 


// links :- https://www.geeksforgeeks.org/problems/next-greater-element/1

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size(), ind = n+n-2;
        stack<int> st;
        vector<int> ans(n, -1);
        
        while(ind >= 0){
            while(!st.empty() && st.top() <= arr[ind%n])
                st.pop();
            
            if(ind < n && !st.empty()){
                ans[ind] = st.top();
            }
            st.push(arr[ind%n]);
            --ind;
        }
        return ans;
    }
};