#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-  
// calculate the frequency of each character 
// use the concept of next greater element and replace the logic of freq in that approach


// links :- https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        for(auto num: arr)
            mp[num] += 1;

        stack<int> st;
        vector<int> ans(n, -1);
        
        for(int ind=n-1; ind>=0; --ind){
            while(!st.empty() && mp[arr[ind]] >= mp[st.top()])
                st.pop();
            
            if(!st.empty() && st.top() != arr[ind])
                ans[ind] = st.top();
            
            st.push(arr[ind]);
        }
        return ans;
    }
};
