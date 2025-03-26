#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*n)
// Space complexity :- O(n + stack_space)

// Approach :-  
// We'll use the memoized solution to implement a better approach
// Insted of checking every prefix of string we'll iterate on the dictionary 
// and try find wheather that word exist in the string from that index or not 
// if it does then we find the further subproblem by passing the index which is ind + dict[i].size()
// if the subproblem return true then return true otherwise check for other word from dictionary
// base case, when ind == n, then return true


//Link :- https://www.geeksforgeeks.org/problems/word-break1352/1

class Solution {
  private:
    bool solve(int ind, string &s, int &n, vector<string> &dictionary, vector<int> &dp){
        if(ind == n)
            return true;
        if(dp[ind] != -1)
            return dp[ind];
        
        bool possible = false;
        
        for(int i=0; i<dictionary.size(); ++i){
            string temp = dictionary[i];
            if(temp.size() > n-ind)
                continue;
            
            int k = ind;
            bool ok = true;
            
            for(int j=0; j<temp.size(); ++j){
                if(temp[j] != s[k]){
                    ok = false;
                    break;
                }
                else    k++;
            }
            if(ok)
                possible |= solve(k, s, n, dictionary, dp);
        }
        return dp[ind] = possible;
    }
  
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, n, dictionary, dp);
    }
};