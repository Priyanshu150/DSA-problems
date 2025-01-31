#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n!)
// Space complexity :- O(n!)

// Approach :- 
// For find permutation of string, we can try recusion and start swapping different index => f(ind, s) will be chaging
// At every stage for a particular ind in string go on to other indexes which is > ind and less than n
// Swapping those two indexes and call recursion 
// At base case when the ind = length - 1 we will insert the premutated string into hashset
// Take hash to remove the duplicate among the permutation
// bracktrack and swap every index back to it's normal place inorder to not distrurb future permutation

//Link :- https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution {
  private:
    void helper(int ind, int &n, string s, unordered_set<string> &st){
        if(ind == n-1){
            st.insert(s);
            return;
        }
        for(int i=ind; i<n; ++i){
            swap(s[ind], s[i]);
            helper(ind+1, n, s, st);
            swap(s[ind], s[i]);
        }
    }
  
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        int n = s.size();
        unordered_set<string> st;
        helper(0, n, s, st);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};