#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N) 

// Approach :-
// For handling the circular operation we can insert k-1 elements from the starting to the back of array
// While traversing we can calulate wheather a window is alternating or not 
// we'll use two pointer (i,j) which will indicate our window with size(i - j + 1)
// we'll start from index i=1 and j=0 because 1 size window will always be alternating 
// if prev_color(i-1) == curr_color(i) then that window is not valid, move j = i
// whenver the size of window becomes k, then that can be one of the valid winow
// increase the j pointer and res += 1 for valid window


//link :- https://leetcode.com/problems/alternating-groups-ii/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), j=0, res=0;

        for(int i=0; i<k-1; ++i)
            colors.push_back(colors[i]);
        
        for(int i=1; i<n+k-1; ++i){
            if(colors[i] == colors[i-1]){
                j = i;
            }
            if(i-j+1 == k){
                res++;
                j++;
            }
        }
        return res;
    }
};