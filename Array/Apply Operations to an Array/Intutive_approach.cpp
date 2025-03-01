#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-
// Traverse the array from left to right and maintain a counter for zeros 
// if we get a 0, increment zero conter and index and continue
// if we get a number such that arr[ind] == arr[ind+1], apply the operation push the res in result arrr
// and increment zeros by 1 and ind by 2
// otherwise push the number into the res array and increment ind by 1
// At last add zeros number of 0 in resultant string


// Link :- https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res;
        int ind = 0, n = nums.size(), zeros = 0;

        while(ind < n){
            int num = nums[ind];

            if(num == 0){
                zeros++;
                ind += 1;
                continue;
            }
            else if(ind+1<n && nums[ind] == nums[ind+1]){
                num *= 2;
                ind += 2;
                zeros++;
            }
            else    ind += 1;

            res.push_back(num);
        }
        while(zeros-->0)
            res.push_back(0);
        return res;
    }
};