#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n!)
// Space complexity :- O(m)

// Approach :-  
// We'll try checking every possibilities for the string and checking if the string exist in the dictionary or not
// there will be only one chaning parameter i.e ind 
// we'll traverse from left to right and try checking for every prefix created if we find the prefix in dictionary
// we'll call the recursion to solve by further by i+1 and checking wheather that give us a valid configuration or not 
// If it does then return true, otherwise check for other prefix and similarly further sub problem
// base case, when ind == n, then return true


//Link :- https://www.geeksforgeeks.org/problems/word-break1352/1

class Solution {
  private:
    bool solve(int ind, int &n, string &s, unordered_set<string> &dict){
        if(ind == n)
            return true;
        
        string str = "";
        for(int i=ind; i<n; ++i){
            str += s[i];
            if(dict.count(str) && solve(i+1, n, s, dict))
                return true;
        }
        return false;
    }
    
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        return solve(0, n, s, dict);
    }
};