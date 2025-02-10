#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// For every index j we know, (nums[j] - j) but we need to find index i having value (nums[i] - i) on the left side 
// which is equal to (nums[j] - j) i.e (nums[j] - j) == (nums[i] - i)
// traversing from left to right we can store the value in hash map and we can check it later
// Standing at index i, the number of new pairs will be i
// And we will find (nums[i] - i) value from map, subtract it from new pair because that will not be bad pairs
// every iteration add new_pairs to the result

// Link :- https://leetcode.com/problems/count-number-of-bad-pairs/

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long res = 0;
            int n = nums.size();
            unordered_map<int, int> mp;
    
            for(int i=0; i<n; ++i){
                int new_pair = i, value = nums[i] - i;
                if(mp.count(value))
                    new_pair -= mp[value];
                
                res += new_pair;
                mp[value] += 1;
            }
            return res;
        }
    };