#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*32)
//Space complexity :- O(N)

// Approach :-
// At every element the xorr value will the all xorr till prev element with curr_element and curr_elemnent itself
// store the xorr into 3 sets, one till the prev element, one for till current element and other for result 
// At max the inner loop will have 32 distinct element, becuae of 32 valid bits 
// the result will be the number of element present in result set 

// link :- https://leetcode.com/problems/bitwise-ors-of-subarrays/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> prev, curr, res;

        for(int i=0; i<n; ++i){
            for(int xorr: prev){
                curr.insert(arr[i] | xorr);
                res.insert(arr[i] | xorr);
            }
            res.insert(arr[i]);
            curr.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return res.size();
    }
};