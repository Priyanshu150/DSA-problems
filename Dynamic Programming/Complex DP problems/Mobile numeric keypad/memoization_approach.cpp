#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*10)       
//Space complexity :- O(N*10)    

//Approach :-
// create a data structure which represents from a particular number where we can traverse next 
// even if we follow any number sequence using given pattern the duplicate number will not arise
// hence we can elimate the logic of hash set 
// step1 :- express every thing in term of prevNum and length of string
// step2 :- express all possibilities, for all the previous number traverse on the adjacent numbers 
//      take the count of numbers which can be formed from that prevNum and call recursion with increased length
// step3 :- accumulate all the ways in variable which will be all the valid count formed from the previous number
// step4 :- the base case will be when length becomes equals to n then return 1
// step5 :- use 2-d dp of size n*10 to memoize the solution 

// Link :- https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

class Solution {
  private:
    vector<vector<int>> keypad = {{0,8}, {1,2,4}, {1,2,3,5}, {2,3,6}, 
        {1,4,5,7}, {2,4,5,6,8}, {3,5,6,9}, {4,7,8}, {0,5,7,8,9}, {6,8,9}};
    
    int solve(int len, int prevNum, int &n, vector<vector<int>> &dp){
        if(len == n){
            return 1;
        }
        if(dp[len][prevNum] != 0)
            return dp[len][prevNum];
        
        int res = 0; 
        for(auto currNum: keypad[prevNum]){
            res += solve(len+1, currNum, n, dp);
        }
        return dp[len][prevNum] = res;
    }
  
  public:
    int getCount(int n) {
        // code here
        int res = 0;
        vector<vector<int>> dp(n+1, vector<int> (10, 0));
        
        for(int i=0; i<10; ++i)
            res += solve(1, i, n, dp);
        
        return res;
    }
};