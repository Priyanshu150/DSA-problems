#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// find the sum of the element of the array, then remainder on the final sum 
// if rem == 2, that mean either we've to remove one element having remainder as 2 
// or two element having remainder as 1
// if rem == 1, that mean either we've to remove one element having remainder as 1
// or two element having remainder as 2
// we'll maintain a separate array for rem1 and rem2, sort them to get smallest 

//Link :- https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> remain1, remain2;

        for(int num: nums){
            sum += num;

            if(num % 3 == 1)
                remain1.push_back(num);
            else if(num % 3 == 2)
                remain2.push_back(num);
        }

        if(sum % 3 == 0)        return sum;

        sort(remain1.begin(), remain1.end());
        sort(remain2.begin(), remain2.end());

        int result = 0;

        if (sum % 3 == 1) {
            int remove1 = remain1.size() >= 1 ? remain1[0] : INT_MAX;
            int remove2 = remain2.size() >= 2 ? remain2[0] + remain2[1] : INT_MAX;
            result      = sum - min(remove1, remove2);
        } 
        else { // sum % 3 == 2
            int remove1 = remain2.size() >= 1 ? remain2[0] : INT_MAX;
            int remove2 = remain1.size() >= 2 ? remain1[0] + remain1[1] : INT_MAX;
            result      = sum - min(remove1, remove2);
        }

        return result < 0 ? 0 : result;
    }
};