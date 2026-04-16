#include <bits/stdc++.h>
using namespace std; 

// Time complexity :- O(n*log(n))
// Space complexity :- O(n)

// Approach :- 
// we'll store all the occurence of element with respect to index into the map i.e. ele1 -> {ind1, ind2, .....}
// find the index which is given to us in query using binary search
// the nearest neigbour will pos+1 and pos-1 which can give us the minimum answer 


// Links :- https://leetcode.com/problems/closest-equal-element-queries/description/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; ++i){
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for(int qi: queries){
            int element = nums[qi];
            vector<int> &vec = mp[element];

            int sz = vec.size();

            // no more occurence of this element 
            if(sz == 1){
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(vec), end(vec), qi) - begin(vec);
            int res = INT_MAX;
            
            // right neighbour - pos + 1
            int right = vec[(pos+1) % sz];
            int d = abs(qi - right);
            int circularDist = n-d;
            res = min({res, d, circularDist});

            // left neighbour - pos-1
            int left = vec[(pos-1+sz) % sz];
            d = abs(qi - left);
            circularDist = n-d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }
        return result;
    }
};