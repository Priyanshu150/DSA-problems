#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-
// use a stack to track the next greater element, manitain a monotonic increasing stack
// whenever a number comes in pop all the element which are less current_num until st.empty()
// If stack becomes empty that means the current_num is the largest
// Otherwise if it there is some element at the top that will be larger than current_num that's why it was not able to pop that 
// at last push the current_num into the stack

// Link :- https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution {
public:
// Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && st.top() <= arr[i])
                st.pop();
            
            if(!st.empty())
                ans[i] = st.top();
            
            st.push(arr[i]);
        }
        return ans;
    }
};
