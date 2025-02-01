#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// Traverse on each element and check whether the adjacent element has same parity
// If yes return false otherwise check for other 
// After checking all you didn't find anything return true

//Link :- https://leetcode.com/problems/special-array-i/

class Solution {
private:
    bool isSameParity(int num1, int num2){
        if((num1%2 && num2%2) || (num1%2==0 && num2%2==0))
            return true;
        
        return false;
    }

public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        for(int i=1; i<n; ++i){
            if(isSameParity(nums[i], nums[i-1]))
                return false;
        }
        return true;
    }
};