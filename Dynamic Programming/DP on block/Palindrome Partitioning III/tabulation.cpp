#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N*log(N) + N*N*log(N))
//Space complexity :- O(1) 

// Approach :-
// Initial the dp array with maxi value and dp[n][0] = 0
// Ind will be from n-1 to 0 and cnt will go from 0 to k
// copy the recurrence 

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

public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1, 1e6));
        dp[n][0] = 0;

        for(int ind=n-1; ind>=0; --ind){
            for(int cnt=0; cnt<=k; cnt++){
                string str = "";

                for(int i=ind; i<n; ++i){
                    str += s[i];
                    int val = convertLetters(str);
                    if(cnt > 0)
                        dp[ind][cnt] = min(dp[ind][cnt], val + dp[i+1][cnt-1]);
                }
            }
        }
        return dp[0][k];
    }
};
