#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(1)              

// Approach :- 
// Use division and remainder method to find the further bottles 

// Links :- https://leetcode.com/problems/water-bottles/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int a = numBottles, b = numExchange;

        while(a/b != 0){
            int exchange = a/b;
            res += exchange;
            a = a%b;
            a += exchange;
        }
        return res;
    }
};