#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
//Space complexity :- O(n)

// Approach :-  
// Take each spell from the spells and find the ceil value of (success / spell)
// we've to find this value in potions array and total element - index will give the count of valid potion
// use binary serach i.e. lower bound for searching in array that's why ceil value will help here


// Link :- https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());

        for(int i=0; i<n; ++i){
            long long val = ceil((double)success/ (double)spells[i]);
            int ind = lower_bound(potions.begin(), potions.end(), val) - potions.begin();
            ans[i] = (m - ind);
        }
        return ans;
    }
};