#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(N)    

//Approach :-

//link :- https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        stack<int> st;
        int ans=0, n = arr.size();
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                int curr = st.top();
                st.pop();

                if(st.empty())
                    break;
                
                int diff = i - st.top() - 1;
                ans += (min(arr[st.top()], arr[i]) - arr[curr])*diff;
            }
            st.push(i);
        }
        return ans;
    }
};