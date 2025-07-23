#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :- 
// use two pointer readIndex and writeIndex 
// the idea is every char before writeIndex is valid 
// once we find a string to be deleted decrement the writeIndex by 2 
// while deleting the string accumulate the point accrodingly 
// Use greedy approach for accumulating the point as we did in stack 

// Link :- https://leetcode.com/problems/maximum-score-from-removing-substrings/

class Solution {
private:
    int pointsForString(string &s, string target, int points){
        int total = 0, writeIndex = 0, n = s.size();

        for(int readIndex=0; readIndex<n; readIndex++){
            s[writeIndex++] = s[readIndex];

            if(writeIndex > 1 && s[writeIndex-1] == target[1] && s[writeIndex-2] == target[0]){
                writeIndex -= 2;
                total += points;
            }
        }
        s = s.substr(0, writeIndex);
        return total;
    }

public:
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if(y > x)   swap(s1, s2), swap(x, y);
        return pointsForString(s, s1, x) + pointsForString(s, s2, y);
    }
};