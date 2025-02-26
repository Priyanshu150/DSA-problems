#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(3*N)       
//Space complexity :- O(N)    

// Approach :-
// For every number if we find out the maximum length of the subarray where it's the min element
// then we can update that element in the our ans array as max(ans[i], curr_element)
// For find the length we can track next_smaller_element(nse) and previous_smaller_element(pse) for current element
// length will be (next_smaller_element - previous_smaller_element - 1) we will put that elemet in ans[len - 1] = current_element
// stack can be use to calulate nse and pse just like in largest area in hostogram problem
// At last we traverse from right to left in the ans array and update the arr[i] = max(arr[i], arr[i+1])


//link :- https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, 0);
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                int num = arr[st.top()], nse, pse, ind;
                st.pop();
                nse = i;
                pse = (st.empty() ? -1 : st.top());
                ind = (nse - pse - 2);
                ans[ind] = max(num, ans[ind]);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int num = arr[st.top()], nse, pse, ind;
            st.pop();
            nse = n; 
            pse = (st.empty() ? -1 : st.top());
            ind = (nse - pse - 2);
            ans[ind] = max(num, ans[ind]);
        }
        
         for(int i=n-2; i>=0; --i)
            ans[i] = max(ans[i], ans[i+1]);
            
        return ans;
    }
};