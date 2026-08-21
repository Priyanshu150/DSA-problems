#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// store each seat number with their row in the map i.e rowId -> bookSeat mapping
// for the rows where no seats  are book, book 2 four seats in that row
// for the reserved check which arrangement can be suited more 
// try encorporating 2 then 1 


// links :- https://leetcode.com/problems/cinema-seat-allocation/description/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reservedSeatInRow;

        for(auto reservedSeat: reservedSeats){
            int row = reservedSeat[0];
            int seat = reservedSeat[1];
            reservedSeatInRow[row].insert(seat);
        }

        int result = (n - reservedSeatInRow.size()) * 2;

        for(auto [row, bookedSeat]: reservedSeatInRow){
            auto isAvailable = [&](int seat){
                return bookedSeat.find(seat) == bookedSeat.end();
            };

            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(groupA && groupC){
                result += 2;
            }
            else if(groupA || groupB || groupC)
                result += 1;
        }
        return result;
    }
};