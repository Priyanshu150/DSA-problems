#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(29 * 10*log(10))
// Space complexity :- O(1)

// Approach :-
// If we sort the given number and store the sorted version of each power of 2 
// then if we found a match then we can say that power of 2 exists 
// store all the number in a set and then check wheather the given number exist in the set or not 


// Link :- https://leetcode.com/problems/reordered-power-of-2/

class Solution {
private:
    unordered_set<string> st;

    string sortedString(int num){
        string str = to_string(num);
        sort(begin(str), end(str));
        return str;
    }

    void powerOf2(){
        for(int p=0; p<=29; ++p){
            st.insert(sortedString(1 << p));
        }
    }

public:
    bool reorderedPowerOf2(int n) {
        if(st.empty()){
            powerOf2();
        }
        string s = sortedString(n);
        return st.count(s);
    }
};