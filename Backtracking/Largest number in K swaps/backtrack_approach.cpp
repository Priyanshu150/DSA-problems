#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2 * (n! / (n-k)!))  
// Space complexity :- O(1)

// Approach :-
// Either use backtracking or greedy, Greedy sounds promising but will not work for case 4577 and repeating number case
// Capitalize on backtracking, for any string we'll find the number of maximum number on right side
// swap the curr char with the larget char and call recursion by decrement k-1 (denotring 1 swap has been used)
// After swapping the current char check wheather the current number formed is max or not 
// we do this in intermediate state because there might be chance that we got answer before using all k swaps
// base case will be when swaps(k) equal 0 or we reach at last char(n)
// one special case will exist where the there is no need for swap (ex- 712)
// for that move to next index without decrementing the swap count and include this case outside loop

// Link :- https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

class Solution {
  private:
    void solve(int ind, int k, string &s, string &res, int &n){
        //base case 
        if(ind == n || k == 0)
            return;
        
        // finding maximum char on right of curr char
        char maxi = *max_element(s.begin()+ind+1, s.end());
        
        // checking all the possible max char on right and swaping them to find largest number
        for(int i=ind+1; i<n; ++i){
            if(s[ind] < s[i] && s[i] == maxi){
                swap(s[ind], s[i]);
                // store the largest number by comparing the 2 string 
                if(s.compare(res) > 0)
                    res = s;
                solve(ind+1, k-1, s, res, n);
                //backtrack to the previous strnig 
                swap(s[ind], s[i]);
            }
        }
        // special case where we didn't use swap and moved to next index
        solve(ind+1, k, s, res, n);
    }
  
 
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        string res = s;
        int n = s.size();
        solve(0, k, s, res, n);
        return res;
    }
};
