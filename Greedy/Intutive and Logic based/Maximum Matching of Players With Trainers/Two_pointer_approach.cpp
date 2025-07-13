#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + m*log(m) + m + n)  
// Space complexity :- O(1)

// Approach :-
// sort both the array of players and trainer 
// use two pointer to traverse on both simultaneously 
// find a trainer for particular player until it not found 
// if found move to the next player 
// also keep track of the count of players matched with trainers using variable


// Link :- https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int m = players.size(), n = trainers.size();
        int i=0, j=0, count = 0;

        while(i<m && j<n){
            if(players[i] > trainers[j]){
                j++;
            }else{
                count++;
                i++;
                j++;
            }
        }
        return count;
    }
};