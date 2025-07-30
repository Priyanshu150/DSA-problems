#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// count the number appearing in the array and store in map
// traverse in the map and check num and cnt 
// if num == 0, then res cnt to answer because all rabit will be have unique color
// if num != 0, then if remainder exist then add 1 to curr_quotient and multiply it with to num
// that many rabit will exist who are say num rabit exist in array with same colors as theirs 


// links :- https://leetcode.com/problems/rabbits-in-forest/


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0, n = answers.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; ++i)
            mp[answers[i]] += 1;
        
        for(auto [num, cnt]: mp){
            res += cnt;
            int rem = cnt%(num+1);
            if(num != 0 &&  rem != 0)
                res += (num+1-rem);
        }
        return res;
    }
};