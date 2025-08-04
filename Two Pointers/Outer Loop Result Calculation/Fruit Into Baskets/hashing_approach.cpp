#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(n)

// Approach :-
// use slinding window approach and map for counting the distinct type of fruit
// start adding the fruit in the basket until the size is less than or equal to 2 
// if it increases from 2 then start removing the fruits from left side of the window 
// maintain the maximum size of window which will be our answer 


// Link :- https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int left = 0, n = fruits.size(), sz = 0, res = 0;

        for(int right=0; right<n; ++right){
            mp[fruits[right]] += 1;
            if(mp[fruits[right]] == 1)
                ++sz;
            
            while(sz > 2){
                mp[fruits[left]] -= 1;
                if(mp[fruits[left]] == 0)
                    sz--;
                
                ++left;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};