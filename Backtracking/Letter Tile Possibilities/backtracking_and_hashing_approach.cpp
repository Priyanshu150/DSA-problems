#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n!)
// Space complexity :- O(n)

// Approach :-  
// Start initially with empty string(temp) and frequency array which mark the index take(freq)
// Add one of the char in temp and mark that as taken in freq array and apply recursion for further cases
// backtrack and undone the following to get other char same place
// Use hash set to store all the sequence generated which in return will delete the duplicate
// If a string is present in the string there is no point continuing because we'll get the same sequence from some tree which we got earlier
// Above step will increase a pruning approach and hence will be slightly faster

// Link :- https://leetcode.com/problems/letter-tile-possibilities/description/

//method 1
class Solution {
    private:
    vector<bool> used;
    unordered_set<string> st;

    void solve(string temp, int &n, string &tiles){
        if(st.count(temp))      return;
        st.insert(temp);

        for(int i=0; i<n; ++i){
            if(used[i])     continue;

            used[i] = true;
            solve(temp + tiles[i], n, tiles);
            used[i] = false;
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        used.resize(n, false);
        solve("", n, tiles);
        return st.size() - 1;
    }
};

//method 2
class Solution {
    private:
    vector<bool> used;
    unordered_set<string> st;

    void solve(string temp, int &n, string &tiles){
        for(int i=0; i<n; ++i){
            if(used[i] == false){
                temp += tiles[i];
                used[i] = true;
                st.insert(temp);
                solve(temp, n, tiles);
                temp.pop_back();
                used[i] = false;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        used.resize(n, false);
        solve("", n, tiles);
        return st.size();
    }
};