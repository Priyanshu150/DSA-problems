#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// we'll maintain two variable where we'll keep track till current index the number which occur once or twice
// for the number that appear thrice it doesn't matter as we only need number appearing once
// we're maintaining the number appearing twice because the number occuring once will be dependent on the logic or twice
// we've to use two function add and deletion from a variable and ^ works best for that case 
// If a number is not in two, then add it into one i.e (one ^ curr_numm) & (~twos)
// if a number is in one, then add it to two i.e (two ^ curr_num) & (~ones)
// if a number is in two, then add it to three 
// ~ will tell us if the nubmer is present in the the particular vairable or not

// Note :- if it work for smaller case then it will work for bigger test case acc to bit logic


//link :- https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int n = arr.size(), ones = 0, twos = 0;
        
        for(int i=0; i<n; ++i){
            ones = (ones ^ arr[i]) & (~twos);
            twos = (twos ^ arr[i]) & (~ones);
        }
        return ones;
    }
};
