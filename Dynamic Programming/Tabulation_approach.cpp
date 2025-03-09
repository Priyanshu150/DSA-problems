#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N^2)
//Space complexity :- O(N^2)

//Approach :-
// We use previously calculate state to calculate wheather current window is a palindrom or not 
// the idea is a or aa is palindrom, then if we add a eqaul char at both side then it also be a palindrom cac and caac
// using this logic we can eliminate the caluclation of palindrome of each string 
// and mainating a 2d dp which can tell wheather the window of size (i+1)(j-1) is a palindrom of not only if s[i] == s[j]
// In 2d dp, we'll travese diagonally for length 1, 2, 3 ... n string size
// 1 length string will be a string, and for the 2 we can check the length of string and if s[i] == s[j] then it will be true
// for other length, if the s[i] == s[j] then we'll check whether the string [i+1] & [j-1] is palindrom or not 
// which we can check via dp[i+1][j-1], then dp[i][j] = 2+dp[i+1][j-1] i.e current length will increase by 2
// And whenever current string is a palindrom then count that in our ans

//link :- https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1

class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        
        for(int i=0; i<n; ++i)
            dp[i][i] = 1;
        
        for(int diff=1; diff<n; ++diff){
            int i=0, j=diff;
            while(j<n){
                if(s[i] == s[j]){
                    if(diff == 1)
                        dp[i][j] = 1;
                    else if(dp[i+1][j-1]>0 )
                        dp[i][j] = 1;
                }
                if(dp[i][j])
                    ++res;
                
                i++, j++;
            }
        }
        return res;
    }
};