#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// For each element find the range/subarray in which the are the smallest element 
// and update in result array => res[len-1] = min(res[len-1], arrr[i])
// where len is length of subbary and res is the resultant array 
// After update traverse from the end and mainatain a maximum element and update it in current position
// For finding the range we can use the concept of PSE/NGE concept of stack 


// links :- https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> st;
        vector<int> leftMin(n, -1), rightMin(n, n);
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                rightMin[st.top()] = i;
                st.pop();
            }
            
            if(!st.empty())
                leftMin[i] = st.top();
            
            st.push(i);
        }
        vector<int> res(n, 0);
        
        for(int i=0; i<n; ++i){
            int width = rightMin[i] - leftMin[i] - 1;
            res[width-1] = max(arr[i], res[width-1]);
        }
        int val = 0;
        
        for(int i=n-1; i>=0; --i){
            val = max(res[i], val);
            res[i] = val;
        }
        return res;
    }
};