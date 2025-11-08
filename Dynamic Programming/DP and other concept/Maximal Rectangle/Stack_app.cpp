#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(m*n)
// Space complexity :- O(n)

// Approach :-  
// This problem is a extention problem of largest area of the histogram 
// We can form the historgram array and then call a function which use that logic to calculate area
// if current_height is 1 then add 1 to previous height otherwise it'll we 0

// links :- 
// leetcode -> https://leetcode.com/problems/maximal-rectangle/description/
// gfg -> https://www.geeksforgeeks.org/problems/max-rectangle/1

class Solution {
  private:
    int findArea(vector<int> arr, int n){
        int res = 0;
        stack<int> st;
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                // find the area of all the element in the stack whose right maximum element is current one 
                int ele = arr[st.top()];
                st.pop();
                
                // the left maximum will be either top of stack or left bounday 
                int pse = st.empty() ? -1 : st.top();
                // formual = length*width = arr[i] * (rightMax - leftMax - 1)
                int area = ele * (i - pse - 1);
                res = max(res, area);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int ele = arr[st.top()];
            st.pop();
                
            int pse = st.empty() ? -1 : st.top();
            int area = ele * (n - pse - 1);
            res = max(res, area);
        }
        return res;
    }
  
  public:
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<int> arr(n, 0);
        
        
        for(int row=0; row<m; ++row){
            for(int col=0; col<n; ++col){
                // Form the histogram 
                if(mat[row][col] == 1)
                    arr[col] = arr[col]+1;
                else 
                    arr[col] = 0;
            }
            // Calculate the area of histogram
            int area = findArea(arr, n);
            res = max(res, area);
        }
        return res;
    }
};