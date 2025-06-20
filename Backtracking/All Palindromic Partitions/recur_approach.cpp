#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*(2^n))
// Space complexity :- O(n*(2^n))

// Approach :- 
// we'll apply backtracking to solve this question 
// Try generating every palindromic subsequence and if we're able to reach at the end 
// then that partion can be our answer
// backtrack once a partition recursion is completed 

// Link :- https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

class Solution {
  private:
    vector<vector<string>> ans;
    
    bool isPalindrome(string &s){
        int n = s.size(), i = 0, j = n-1;
        
        while(i < j){
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int ind, int &n, string &s, vector<string> temp){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        string str = "";
        
        for(int i=ind; i<n; ++i){
            str += s[i];
            if(isPalindrome(str)){
                temp.push_back(str);
                solve(i+1, n, s, temp);
                temp.pop_back();
            }
        }
    }
  
  public:
    vector<vector<string>> palinParts(string &s) {
        // code here
        int n = s.size();
        solve(0, n, s, {});
        return ans;
    }
};