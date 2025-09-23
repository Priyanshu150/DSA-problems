#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(N)    

// Approach :-
// The idea is to find the largest element from the current element from the left side 
// monotonic stack can be used in order to efficienct keep track of the same 
// we can use a pair<int,int> = {arr[i], i} and keep it in the stack
// that way we can track the length  i - curr_ind

//link :- https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && st.top().first <= arr[i])
                st.pop();
            
            if(!st.empty())
                ans.push_back(i - st.top().second);
            else
                ans.push_back(i+1);
                
            st.push({arr[i], i});
        }
        return ans;
    }
};