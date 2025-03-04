#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(n) with base 3)
// Space complexity :- O(1)

//Approach :- 
// https://www.youtube.com/watch?v=v4JXz_z4Jk0

//Link :- https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            if(n%3 == 2)
                return false;
            
            n /= 3;
        }
        return true;
    }
};