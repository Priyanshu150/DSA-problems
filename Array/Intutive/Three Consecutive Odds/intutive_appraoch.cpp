#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-
// check if the continuous 3 elements are odd then return true
// checking element is odd or not, arr[i]%2 == 1 || arr[i]&1


// Link :- https://leetcode.com/problems/three-consecutive-odds/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i+2<n; ++i){
            if(arr[i]&1 && arr[i+1]&1 && arr[i+2]&1)
                return true;
        }
        return false;
    }
};