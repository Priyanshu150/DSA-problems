#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for(int i=0; i<n; ++i)
            pq.push({nums[i], i});
        
        long long score = 0;
        while(!pq.empty()){
            int ele = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            if(marked[ind])     continue;

            score += ele;
            marked[ind] = true;
            if(ind-1 >= 0)      marked[ind-1] = true;
            if(ind+1 < n)       marked[ind+1] = true;
        }
        return score;
    }
};