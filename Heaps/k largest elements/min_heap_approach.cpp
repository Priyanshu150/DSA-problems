#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + k + n)
// Space complexity :- O(k)

// Approach :-  
// Use min heap and add all the array element in that. If the size increase from k remove element from top
// After traversing all the element we'll have k larget element in the heap 

// Link :- https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution {
    public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(auto num: arr){
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

