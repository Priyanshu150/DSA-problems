#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + k)
// Space complexity :- O(k)

// Approach :-  
// Calculate the distance of each point from the origin and put it into max heap along with coordinates
// If the size of heap increase by k then pop the top element
// we're taking max heap for distance because we want the heap to store element in increasing distance so every time we pop the largest distance gets out 

// Link :- https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1

class Solution {
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>> ans;
        priority_queue<vector<int>> pq;
        
        for(auto point: points){
            int x = point[0], y = point[1];
            int dis = x*x + y*y;
            pq.push({dis, x, y});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()){
            int x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            
            ans.push_back({x, y});
        }
        return ans;
    }
};