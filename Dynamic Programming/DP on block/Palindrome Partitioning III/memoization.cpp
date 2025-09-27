#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*N*K)
//Space complexity :- O(N*K) 

// Approach :-
// Try out creating all possibility to get the partition where minimum char conversion occur
// the changing parameter will be ind and cnt of partitions
// explore all possibilites, try creating front partition of the string 
// for every partion calculate the conversion we need and call the sub-problem 
// answer will be minimum value among all possibilites 
// base case will be whenever ind becomes n and cnt == 0 then we can return 0 i.e valid case 
// otherwise return maximum number 
// we can memoize the solution using 2-d dp [n][k]

//link :- https://leetcode.com/problems/palindrome-partitioning-iii/

class Solution {
private:
    int convertLetters(string str){
        int n = str.size();
        int i=0, j=n-1, res = 0;

        while(i < j){
            if(str[i] != str[j])
                res++;
            
            i++;
            j--;
        }
        return res;
    }

    int solve(int ind, int cnt, string &s, int &n, vector<vector<int>> &dp){
        if(ind == n){
            return (cnt > 0) ? 1e6 : 0;
        }
        if(dp[ind][cnt] != -1)
            return dp[ind][cnt];

        string str = "";
        int res = 1e6;

        for(int i=ind; i<n; ++i){
            str += s[i];
            int val = convertLetters(str);
            if(cnt > 0)
                res = min(res, val + solve(i+1, cnt-1, s, n, dp));
        }
        return dp[ind][cnt] = res;
    }

public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return solve(0, k, s, n, dp);
    }
};
