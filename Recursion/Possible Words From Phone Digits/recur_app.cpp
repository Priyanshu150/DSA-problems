#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(4^n)
// Space complexity :- O(n*4^n)

// Approach :-  
// create a  ds having all the data for the keypad 
// use recusion, to traverse on each string one by one and create all the possibilites of string


// Link :- https://www.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1

class Solution {
  private:
    int n;
    vector<string> ans;
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void solve(int ind, string temp, vector<int> &arr){
        // base case
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        string str = keypad[arr[ind]];
        // The number is 0 and 1 then 
        if(str == ""){
            solve(ind+1, temp, arr);
        }
        // try creating all the sequence using recursion
        for(int i=0; i<str.size(); ++i){
            solve(ind+1, temp+str[i], arr);
        }
    }
  
  public:
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        n = arr.size();
        solve(0, "", arr);
        return ans;
    }
};