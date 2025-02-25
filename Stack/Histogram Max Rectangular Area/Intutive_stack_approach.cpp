#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(3*N)       
//Space complexity :- O(3*N)    

// Approach :-
// For find area we can use fomula, (rightBoundary[curr_ind] - leftBoundary[curr_ind] + 1)*arr[i] i.e length*breadth
// we use stack and find the leftBoundary and rightBoundary for each index and put it into vector
// we can use the concept of next-smallest-element to find these using monotonic stack


//link :- https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1


class Solution {
  private:
    void findBoundary(int i, int j, int k, vector<int> &arr, vector<int> &boundaryArr){
        int n = arr.size();
        stack<int> st;
        
        for(int ind=i; ind!=j; ind+=k){
            while(!st.empty() && arr[ind] <= arr[st.top()])
                st.pop();
            
            if(!st.empty())
                boundaryArr[ind] = st.top();
            
            st.push(ind);
        }
    }
  
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size(), res = 0;
        vector<int> leftBoundary(n, -1), rightBoundary(n, n);
        
        findBoundary(0, n, 1, arr, leftBoundary);
        findBoundary(n-1, -1, -1, arr, rightBoundary);
        
        for(int i=0; i<n; ++i){
            int area = arr[i] * (rightBoundary[i] - leftBoundary[i] - 1);
            res = max(area, res);
        }
        return res;
    }
};

class Solution {
    private:
    void findBoundary(int i, int j, int k, vector<int> &arr, vector<int> &boundaryArr){
        int n = arr.size();
        stack<int> st;
        
        for(int ind=i; ind!=j; ind+=k){
            while(!st.empty() && arr[ind] <= arr[st.top()])
                st.pop();
            
            if(!st.empty())
                boundaryArr[ind] = st.top();
            
            st.push(ind);
        }
    }
  
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size(), res = 0;
        vector<int> leftBoundary(n, -1), rightBoundary(n, n);
        
        findBoundary(0, n, 1, arr, leftBoundary);
        findBoundary(n-1, -1, -1, arr, rightBoundary);
        
        for(int i=0; i<n; ++i){
            int area = arr[i] * (rightBoundary[i] - leftBoundary[i] - 1);
            res = max(area, res);
        }
        return res;
    }
};