#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^n)
// Space complexity :- O(n)

// Approach :-   
// try making a string of length n by either taking 0 and 1
// try all possible sequence and backtrack once didn't find answer for a particular sequence
// At base case, check wheather that string already exists if not save the result and return

// Link :- https://leetcode.com/problems/find-unique-binary-string/

class Solution {
    private:
    unordered_set<string> st;

    string solve(string temp, int &n){
        if(temp.size() == n){
            if(!st.count(temp))     return temp;
            return "";
        }
        string res = solve(temp + '0', n);
        if(res != "")
            return res;

        res = solve(temp + '1', n);
        if(res != "")
            return res;
        
        return "";
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        st = unordered_set<string> (nums.begin(), nums.end());
        return solve("", n);
    }
};