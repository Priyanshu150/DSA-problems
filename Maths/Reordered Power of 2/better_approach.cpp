#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(29 * 10*log(10)) 
// Space complexity :- O(1)

// Approach :-
// If we sort the given number and store the sorted version of each power of 2 
// then if we found a match then we can say that power of 2 exists 

// Link :- https://leetcode.com/problems/reordered-power-of-2/

class Solution {
private:
    string sortedString(int num){
        string str = to_string(num);
        sort(begin(str), end(str));
        return str;
    }

public:
    bool reorderedPowerOf2(int n) {
        string s = sortedString(n);

        for(int p=0; p<=29; ++p){
            if(s == sortedString(1<<p))
                return true;
        }
        return false;
    }
};