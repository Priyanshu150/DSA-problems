#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(M*N + M*log(M))
// Space complexity :- O(N)

// Approach :-  
// sort the meeting accordingly
// maintain an array to track the n rooms with their meeting time or no meeting
// for every meeting find either the next empty room or the room where the meeting will end sooner
// schedule the next meeting in that room and make the adjustment accordingly 
// use an array to count the frequency of meeting happening in each room 


// links :- https://leetcode.com/problems/meeting-rooms-iii/

class Solution {
#define ll long long

public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<ll> rooms(n, -1), meetingCnt(n, 0);
        sort(meetings.begin(), meetings.end());

        for(auto meeting: meetings){
            ll st = meeting[0], end = meeting[1];
            ll roomNo = -1, leastEndTime = LLONG_MAX;
            bool meetingScheduled = false;

            for(int i=0; i<n; ++i){
                if(rooms[i] <= st){
                    meetingCnt[i] += 1;
                    rooms[i] = end;
                    meetingScheduled = true;
                    break;
                }
                if(rooms[i] < leastEndTime){
                    leastEndTime = rooms[i];
                    roomNo = i;
                }
            }
            if(!meetingScheduled){
                meetingCnt[roomNo] += 1;
                rooms[roomNo] = (ll)(leastEndTime + (ll)(end - st));
            }
        }
        int res = -1, maxMeeting = 0;
        for(int i=0; i<n; ++i){
            if(maxMeeting < meetingCnt[i]){
                maxMeeting = meetingCnt[i];
                res = i;
            }
        }
        return res;
    }
};
