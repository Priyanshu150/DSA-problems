#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// Put the arrival and deparature time of train in a array and sort it based on starting time
// For keeping track of the trains that are already on platform we can use heap
// the heap has to be  min heap to check which will depart first (store ending time of train)
// traverse from left to right based on starting time of trains 
// if next departing train i.e. top of minHeap then pop the element from the queue representing train has departed 
// push the ending time into the queue
// At last the the total number of element present in the minHeap will be the platform needed



//Link :- https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size();
        vector<pair<int,int>> temp;
        
        for(int i=0; i<n; ++i)
            temp.push_back({arr[i], dep[i]});
        
        sort(temp.begin(), temp.end());
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(temp[0].second);
        
        for(int i=1; i<n; ++i){
            if(pq.top() < temp[i].first)
                pq.pop();
            
            pq.push(temp[i].second);
        }
        return pq.size();
    }
};