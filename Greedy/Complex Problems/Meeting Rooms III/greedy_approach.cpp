#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(M*log(M) + N*log(N))
// Space complexity :- O(M)

// Approach :-  
// instead of array we can use 2 minheaps to track the next available room 
// first minheap will be of type int where we're storing all the empty rooms
// second minheap will be the occupied rooms with their ending time 
// sort the meeting accordingly
// then traverse on each meeting and empty the occupied room which have ending time <= current_meeting_starting_time
// if there is any empty room schedule the meeting in that room 
// otherwise find the next available room adjust the timing accordingly and schedule the meeting
// use an array to count the frequency of meeting happening in each room 


// links :- https://leetcode.com/problems/meeting-rooms-iii/

class Solution {
#define ll long long
#define pii pair<ll, int>

public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<ll> meetingCnt(n, 0);
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<pii, vector<pii>, greater<pii>> ongoingMeetings;

        for(int i=0; i<n; ++i)
            availableRooms.push(i);

        for(auto meeting: meetings){
            int st = meeting[0], end = meeting[1];

            while(!ongoingMeetings.empty() && ongoingMeetings.top().first <= st){
                int roomNo = ongoingMeetings.top().second;
                ongoingMeetings.pop();
                availableRooms.push(roomNo);
            }

            if(!availableRooms.empty()){
                int roomNo = availableRooms.top();
                availableRooms.pop();

                meetingCnt[roomNo]++;
                ongoingMeetings.push({end, roomNo});
            }
            else{
                ll leastEndTime = ongoingMeetings.top().first;
                int roomNo = ongoingMeetings.top().second;
                ongoingMeetings.pop();

                meetingCnt[roomNo]++;
                ll newEndTime = (leastEndTime + (ll)(end - st));
                ongoingMeetings.push({newEndTime, roomNo});
            }
        }
        int res, maxMeeting = 0;
        for(int i=0; i<n; ++i){
            if(maxMeeting < meetingCnt[i]){
                maxMeeting = meetingCnt[i];
                res = i;
            }
        }
        return res;
    }
};