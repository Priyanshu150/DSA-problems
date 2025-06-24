#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2*n)  
// Space complexity :- O(1)

// Approach :-
// for any top or bottom columns, count the number of maximum element occuring 
// traverse again and check for those places where it's not occuring 
// wheather it's occuring in other sequencece, then count the number of flips in that way
// if not occuring then it's not possbile 
// call this function twice one considering for top and other time considering for bottom


// Link :- https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution {
private:
    int solve(vector<int> &a, vector<int> &b, int &n){
        int maxOcc = 0, num = -1, flips = 0;
        vector<int> freq(7, 0);

        for(int i=0; i<n; ++i){
            freq[a[i]] += 1;
            if(freq[a[i]] > maxOcc){
                maxOcc = freq[a[i]];
                num = a[i];
            }
        }
        for(int i=0; i<n; ++i){
            if(a[i] != num){
                if(b[i] == num)
                    flips++;
                else 
                    return INT_MAX;
            }
        }
        return flips;
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), res;
        res =  min(solve(tops, bottoms, n), solve(bottoms, tops, n));
        return (res == INT_MAX) ? -1 : res;
    }
};