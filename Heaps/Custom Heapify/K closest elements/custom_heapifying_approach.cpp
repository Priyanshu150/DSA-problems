#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(K))
// Space complexity :- O(K)

// Approach :-  
// Use heap and store number in pair format 
// where first element will be diff b/w target & number and second parameter will be current_number
// use custom sorting technique to heapify the element 
// traverse on the array and maintain the difference and push them into the heap
// once the size increases by k pop the top element
// that way we'll get k element having minmum difference 


// Link :- https://www.geeksforgeeks.org/problems/k-closest-elements3619/1

struct comp{
    bool operator()(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first == p2.first)
            return p1.second > p2.second;
        
        return p1.first < p2.first;
    }
};

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        int n = arr.size();
        
        for(int i=0; i<n; ++i){
            int diff = abs(arr[i] - x);
            if(diff == 0)       continue;
            
            pq.push({diff, arr[i]});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};