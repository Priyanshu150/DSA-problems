#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(1)    

// Approach :- 
// If we fix the value of first element i.e 'x' then we can calulate the rest of sequence of array
// maintain the maximum and minimum element of array, that will be in terms of x 
// if we subtract the value of (max_ele - min_ele) then we'll get a range, range in which array element will lie
// (lower - upper + 1) will be the given range according to problem
// the diffenece b/w both the range will give us the number of element that can be accomodated in
// if the diff is negative then return 0 denoting it's not possible other return the diff 

// (logic) if we put the min_element at the lower and the range of element of array is short of upper values
// then we can shift the min_element element 1 at a time to get it touch upper value
// the times we shift lower value will be number of valid sequence 


// Links :- https://leetcode.com/problems/count-the-hidden-sequences/

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long curr = 0, mini = 0, maxi = 0;

        for(int diff: differences){
            curr += diff;
            mini = min(curr, mini);
            maxi = max(curr, maxi);
        }
        long range = (maxi - mini), bound = upper - lower + 1;
        int res = (int)(bound - range);
        return  res > 0 ? res : 0;
    }
};