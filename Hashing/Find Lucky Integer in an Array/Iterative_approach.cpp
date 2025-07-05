#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// count the freq of each number in the array 
// traverse the map and find the highest number where freq of number equal to number 

// links :- https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(auto num: arr){
            mp[num] += 1;
        }
        int res = -1;
        
        for(auto it: mp){
            if(it.first == it.second)
                res = max(res, it.first);
        }
        return res;
    }
};