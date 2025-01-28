#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(9^n)
// Space complexity :- O(n!)

// Approach :- 
// For creating permutation of string, we start with empty string(str) & original string(s)
// At every stage of recursion we pick one char from the s and add it str
// The char that was added we delete it from s and call recursion to add the rest char
// For base case, whenever we added all the char to str then s will be empty
// Add all the str in hash set in order to eliminate the duplicates
// Backtack and add the char which we have deleted from s 

//Link :- https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution {
  private:
    void helper(string str, string s, unordered_set<string> &st){
        if(s == ""){
            st.insert(str);
            return;
        }
        for(int ind=0; ind<s.size(); ++ind){
            str.push_back(s[ind]);
            string ros = s.substr(0, ind) + s.substr(ind+1);
            helper(str, ros, st);
            str.pop_back();
        }
    }
  
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        unordered_set<string> st;
        helper("", s, st);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};