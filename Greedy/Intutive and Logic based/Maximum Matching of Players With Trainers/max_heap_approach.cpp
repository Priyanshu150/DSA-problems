#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n) + m*log(m) + m*log(n))  
// Space complexity :- O(n)

// Approach :-
// use maxheap to keep track of all the trainers and sort the players array in non-increasing order
// for every player try checking on the top of the maxHeap if a trainer match 
// if it does remove it from the heap and move to next player
// also keep track of the count of players matched with trainers using variable 


// Link :- https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int> pq;
        sort(players.begin(), players.end(), greater<int> ());

        for(auto trainer: trainers)
            pq.push(trainer);
        
        int res = 0;
        for(auto player: players){
            if(!pq.empty() && player <= pq.top()){
                pq.pop();
                res++;
            }
        }
        return res;
    }
};