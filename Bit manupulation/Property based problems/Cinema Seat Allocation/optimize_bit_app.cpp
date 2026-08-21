#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// since there are 10 seats we can use bitMask to update the seat allocation 
// for every row create a bitMask of seat and keep it in the map
// calculate the bitMask of all 3 four seats arrangement
// if bitMask of row and seat arragement is 0, then that arrangement is possible
// use greedy technique to alloacate maximum seat

// links :- https://leetcode.com/problems/cinema-seat-allocation/description/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedSeatInRow;

        for(auto reservedSeat: reservedSeats){
            int row = reservedSeat[0];
            int seat = reservedSeat[1];
            reservedSeatInRow[row] |= (1 << seat);
        }

        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        int result = (n - reservedSeatInRow.size()) * 2;

        for(auto [row, bookedSeatMask]: reservedSeatInRow){
            bool groupA = (maskA & bookedSeatMask) == 0;
            bool groupB = (maskB & bookedSeatMask) == 0;
            bool groupC = (maskC & bookedSeatMask) == 0;

            if(groupA && groupC){
                result += 2;
            }
            else if(groupA || groupB || groupC)
                result += 1;
        }
        return result;
    }
};