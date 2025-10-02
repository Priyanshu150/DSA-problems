#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(1)              

// Approach :- 
// use logical approach and replicate the scenario explained in the question 

// Links :- https://leetcode.com/problems/water-bottles-ii/

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = numBottles, drank = emptyBottles;

        while(numExchange <= emptyBottles){
            emptyBottles -= numExchange;
            drank += 1;
            emptyBottles += 1;
            numExchange += 1;
        }
        return drank;
    }
};

