#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n!)
// Space complexity :- O(n)

// Approach :-   
// Try out all possible sequence to try keep number of every number at n+1 places
// Mark the number which we tried to put at a place and try recusion to generate valid sequence 
// If we succesed return from that point other backtrack and try to place other number at same place
// The return type of recusion should be boolean in order to know from recusion call wheather we successed in creating a valid sequence
// Before putting a number check whether is following the pattern or not then only place the valid numbers

// Link :- https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution {
    private:
    vector<bool> used;

    bool check(char curr, char prev, char order){
        if(order == 'I')
            return (curr - '0') > (prev - '0');
        
        return (curr - '0') < (prev - '0');
    }

    bool solve(int ind, string &res, int &n, string &pattern){
        if(ind == n+1)
            return true;
        
        for(char ch='1'; ch<='9'; ++ch){
            if(ind == 0 || (used[ch - '0'] == false && check(ch, res[ind-1], pattern[ind-1]) )){
                res += ch;
                used[ch-'0'] = true;

                if(solve(ind+1, res, n, pattern))
                    return true;
                
                res.pop_back();
                used[ch-'0'] = false;
            }
        }
        return false;
    }

public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        used.resize(10, false);
        string res = "";
        solve(0, res, n, pattern);
        return res;
    }
};