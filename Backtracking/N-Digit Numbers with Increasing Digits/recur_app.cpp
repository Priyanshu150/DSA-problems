#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(9^n)
// Space complexity :- O(1)

// Approach :- 
// digit > 9 is not possible so return empty array 
// for less than 9 try all ways to create all valid numbers 

//Link :- https://www.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1


class Solution {
  private:
    void solve(int ind, int &n, int num, vector<int> &ans){
        // base case: digit equals to the lenght of number
        if(ind == n){
            ans.push_back(num);
            return;
        }
        // find the previous number 
        int prev = num % 10;
        
        for(int next=1; next<10; ++next){
            // take the increasing digit only 
            if(next > prev){
                // include the current digit 
                num = num*10 + next;
                solve(ind+1, n, num, ans);
                // backtrack the previous digit 
                num /= 10;
            }
        }
    }
  
  public:
    vector<int> increasingNumbers(int n) {
        vector<int> ans;
        // number of having more than 9 digit are not posssible 
        if(n > 9)       return ans;
        // add 0, when digits == 1
        if(n == 1)      ans.push_back(0);
        // call recursion 
        solve(0, n, 0, ans);
        return ans;
    }
};
