#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)    

//Approach :-
// For find all pair xor we need to find how many times an element is occuring
// Element in num1 will occur length of num2 times and vice-versa
// While counting modulo the cnt by 2 to get value either as 0 or 1
// At last, the number which is occuring odd number of time take xor of all that number

//link :- https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), res = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<n; ++i)
            mp[nums1[i]] += (m%2);
        
        for(int i=0; i<m; ++i)
            mp[nums2[i]] += (n%2);
        
        for(auto it: mp){
            if(it.second%2)
                res ^= it.first;
        }
        return res;
    }
};