#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-  
// check for how many subarray an element is contributing
// this can we found by using a formula i.e. 
// find the smallest element on the left of current element i.e previous smallest element (pse)
// and find the smallest element or equal element on the right of current element i.e next smallest or equal element (nsee)
// the total array that current element is contribution will be (ind - pse[ind]) * (nse[ind] - ind)
// find the indvidual contribution of each element and add it to the result variable 


// links :- https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

class Solution {
  private:
    vector<int> findPSE(vector<int> &arr, int &n){
        stack<int> st;
        vector<int> ans(n, -1);
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            
            if(!st.empty())     ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> findNSEE(vector<int> &arr, int &n){
        stack<int> st;
        vector<int> ans(n, n);
        
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            
            if(!st.empty())     ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
  
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size(), res = 0;
        vector<int> pse = findPSE(arr, n);
        vector<int> nse = findNSEE(arr, n);
        
        for(int i=0; i<n; ++i){
            int subarrays = (nse[i] - i) * (i - pse[i]);
            res += (arr[i] * subarrays);
        }
        return res;
    }
};