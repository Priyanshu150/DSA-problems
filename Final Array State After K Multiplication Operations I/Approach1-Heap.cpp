#include<bits/stdc++.h>
using namespace std;

//Modifing the array

class Solution {
    #define pii pair<int,int>

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for(int i=0; i<n; ++i)
            pq.push({nums[i], i});
        
        while(k--){
            int ele = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            ele = ele*multiplier;
            nums[ind] = ele;
            pq.push({ele, ind});
        }
        return nums;
    }
};

//Wihtout modifing the array

class Solution {
    #define pii pair<int,int>

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> ans(n, -1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for(int i=0; i<n; ++i)
            pq.push({nums[i], i});
        
        while(!pq.empty()){
            int ele = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            if(k-- > 0){
                ele = ele*multiplier;
                pq.push({ele, ind});
            }
            ans[ind] = ele;
        }
        return ans;
    }
};