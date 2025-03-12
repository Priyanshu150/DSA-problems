#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^n)  
// Space complexity :- O(n*n)

// Approach :-
// For this problem we've to try all possibilities inorder to get minimum cost
// ind will be changing parameter as we've to traverse on all the indexes possible in array
// Initially we'll start from top i.e n and go on previous index to explore all possibilities
// we will check the 1st option, which is go on ind-1 and explore all the possibilites
// we will check the 2nd option, which is go on ind-2 and explore all the possibilites
// whichever option gives the minimum answer return that by adding current cost of index i.e. cost[ind]
// if we're standing at index n, then the cost will be 0
// base case will be whenever we're at 0 or 1 we'll return cost[0] and cost[1] respectively


// Link :- https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

class Solution {
  private:
    int helper(int ind, int &n, vector<int> cost){
        if(ind == 0 || ind == 1)
            return cost[ind];
        
        int val = (ind == n) ? 0 : cost[ind];
        int opn1 = helper(ind-1, n, cost);
        int opn2 = helper(ind-2, n, cost);
        
        return val + min(opn1, opn2);
    }
  
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        return helper(n, n, cost);
    }
};