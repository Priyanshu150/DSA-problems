#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(32 + q*32)
//Space complexity :- O(32)

// Approach :-
// The number present in the power we can directly find which bits are set in n
// and accrodingly that will be our number present in powers 
// for every query we can directly traverse on the power array and find the answer 
// take long long as prod as the number will exceed the limit due to its contraints
// the power will only have 32 number at max hence the time complexity remains q*32  


//link :- https://leetcode.com/problems/range-product-queries-of-powers/

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        vector<int> powers, ans;

        for(int bit=0; bit<32; ++bit){
            if(n & (1<<bit)){
                powers.push_back(1<<bit);
            }
        }

        for(auto query: queries){
            int left = query[0], right = query[1];
            long val = 1;
            
            for(int i=left; i<=right; ++i){
                val = (val * powers[i]) % mod;
            }
            
            ans.push_back(val);
        }
        return ans;
    }
};

