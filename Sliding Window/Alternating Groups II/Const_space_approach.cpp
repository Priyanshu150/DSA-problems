#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(1) 

// Approach :-
// We'll use the same approach what we've used in spaced approach 
// But to eliminate adding extra number we can use modulo operator 
// we'll increment the i accordingly and do mod with n so that it'll be wrapped around to circular value


//link :- https://leetcode.com/problems/alternating-groups-ii/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), j=0, res=0;
        
        for(int i=1; i<n+k-1; ++i){
            if(colors[i%n] == colors[(i-1)%n]){
                j = i;
            }
            if(i-j+1 == k){
                res++;
                j++;
            }
        }
        return res;
    }
};