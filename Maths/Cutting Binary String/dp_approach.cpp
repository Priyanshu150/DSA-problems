#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

//Approach :- 
// since only 1 state is changing use 1-d dp to memoize the recursive solution

//Link :- https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1

class Solution {
  private:
    unordered_set<int> st;
  
    void powerof5(){
        int num = 1;
        while(num < 1e9){
            st.insert(num);
            num *= 5;
        }
    }
  
    int solve(int ind, string &s, int &n, vector<int> &dp){
        if(ind == n)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
        int res = 1e8, val = 0;
        
        for(int i=ind; i<n; ++i){
            val = (val*2) + (s[i] - '0');
            if(s[ind] != '0' && st.count(val)){
                res = min(res, 1+solve(i+1, s, n, dp));
            }
        }
        return dp[ind] = res;
    }
 
  public:
    int cuts(string s) {
        // code here
        int n = s.size();
        vector<int> dp(n, -1);
        powerof5();
        int res = solve(0, s, n, dp);
        return (res == 1e8) ? -1 : res;
    }
};