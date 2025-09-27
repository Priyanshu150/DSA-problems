#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*N + N*3)
//Space complexity :- O(N*N + N*3)

// Approach :-
// pre-calculate the information of palindrom b/w substring 
// for base express, initialize dp with false and dp[n][0] = true
// ind will go from n-1 to 1 and cnt from 3 to 0
// copy paste the recurence condition 

//link :- https://leetcode.com/problems/palindrome-partitioning-iv/

class Solution {
private:
    bool isPalindrome(int i, int j, string str){
        while(i < j){
            if(str[i] != str[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }

    bool isPalindrome(int i, int j, string &s, vector<vector<int>> &palindrome){
        if(i > j)   return true;
        if(palindrome[i][j] != -1)
            return palindrome[i][j];
        
        bool ans = false;
        if(s[i] == s[j])
            ans |= isPalindrome(i+1, j-1, s, palindrome);
        
        return palindrome[i][j] = ans;
    }

public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> palindrome(n+1, vector<int> (n+1, -1));

        for(int i=0; i<n; ++i){
            for(int j=i; j<n; ++j){
                isPalindrome(i, j, s, palindrome);
            }
        }
        vector<vector<bool>> dp(n+1, vector<bool> (4, false));
        dp[n][0] = true;

        for(int ind=n-1; ind>=0; --ind){
            for(int cnt=3; cnt>0; --cnt){
                for(int i=ind; i<n; ++i){
                    if(palindrome[ind][i]){
                        dp[ind][cnt] = dp[ind][cnt] | dp[i+1][cnt-1];
                    }
                }
            }
        }
        return dp[0][3];
    }
};
