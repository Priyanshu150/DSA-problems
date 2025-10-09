#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m)
//Space complexity :- O(n)

// Approach :-  
// use an array to store the time taken by each wizard initially 0
// Start processing each mana one by one 
// whenever a wizard is getting free assign it to complete the task and calculate the time store 
// i.e. finish[j] = max(finish[j-1], finish[j]) + skill[j]*mana[i];
// Afterward correct the timming of completion based on the next wizard complting task time
// finish[j-1] = finish[j] - skill[j]*mana[i];


// Link :- https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> finish(n, 0);

        for(int i=0; i<m; ++i){
            // time taken by first wizard 
            finish[0] = finish[0] + skill[0]*mana[i];
            // time take by rest wizard (2 - last)
            for(int j=1; j<n; ++j){
                finish[j] = max(finish[j-1], finish[j]) + skill[j]*mana[i];
            }
            // correct the timming based on the next ending time 
            for(int j=n-1; j>0; --j){
                finish[j-1] = finish[j] - skill[j]*mana[i];
            }
        }
        return finish[n-1];
    }
};