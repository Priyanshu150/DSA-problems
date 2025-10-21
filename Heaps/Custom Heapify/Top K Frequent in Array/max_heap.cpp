#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*log(K))
// Space complexity :- O(K)

// Approach :-  


// Link :- https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

#define pi pair<int,int>

struct comp{
    bool operator()(pi &p1, pi &p2){
        if(p1.first == p2.first)
            return p1.second > p2.second;
        
        return p1.first > p2.first;
    }
};

class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int> mp;
        // count the frequency of each element using hash map
        for(auto ele: arr)
            mp[ele] += 1;
        
        // use heap in form of {ele, cnt} 
        priority_queue<pi, vector<pi>, comp> pq;
        
        // maintain top k element having most freqency in asc ord 
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        // reverse the answer to find the final order in desc order
        reverse(res.begin(), res.end());
        return res;
    }
};
