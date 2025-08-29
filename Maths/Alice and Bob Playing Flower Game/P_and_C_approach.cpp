#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(1)
// Space complexity :- O(1)

//Approach :- 
// Whenver the sum of flower present in both the lanes is eqaul to odd number then Alice wins
// In order to keep overall odd number of flower in both lanes
// we've to keep odd & even number of flower in two lanes and vice-versa 
// the number of ways will be selecting odd flower in 1st lane and even flower in 2nd lane and vice versa

//Link :- https://leetcode.com/problems/alice-and-bob-playing-flower-game/

class Solution {
    #define ll long long 

public:
    long long flowerGame(int n, int m) {
        ll even1 = (n/2), odd1 = n - even1;
        ll even2 = (m/2), odd2 = m - even2;
        return (even1*odd2) + (odd1*even2);
    }
};