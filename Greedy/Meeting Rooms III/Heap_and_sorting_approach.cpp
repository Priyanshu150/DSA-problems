#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))  
// Space complexity :- O(n)

// Approach :-
// firstly, sort the array based on the starting time 
// maintain a hash where we store how many time we've used a single room for meeting
// maintain 2 minHeap, freeRoom tracks the room available for meeting => initially push all the room
// other pq minhead stores the ending time and room used in form of pair
// take each meeting at a time from sorted version and do these operation for all meeting
// while the start time of current meeting is less that ending time of meeting in pq
// pop all those and put into freeRoom heap
// now if we've freeRoom avaiable accomodate the meeting in the lowest numbered room which minheap will handle
// and increase the count of that room been use and remove it from free room
// otherwise find when next room will be available, calculate the delay in time and adjust timing
// accomodate the meeting in that room and increase & update value in meap and hash at the same time
// At last calculate the value using hash which we creating


// Link :- https://www.geeksforgeeks.org/problems/meeting-rooms-iii/1

class Solution {
  private:
    static bool compare(vector<int> &meeting1, vector<int> &meeting2){
        if(meeting1[0] == meeting2[0])
            return meeting1[1] < meeting2[1];
        
        return meeting1[0] < meeting2[0];
    }
  
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        vector<int> meetingsCount(n, 0);
        // sorting based on start time
        sort(meetings.begin(), meetings.end(), compare);
        
        // minHeap for all the freeRoom
        priority_queue< int, vector<int>, greater<int>> freeRoom;
        
        // Initally all rooms are free 
        for(int i=0; i<n; ++i)
            freeRoom.push(i);
        
        // custom comparator for minHeap
        auto compare = [](const pair<int, int> &a, const pair<int, int> &b){
            if(a.first == b.first)
                return a.second > b.second;
            
            return a.first > b.first;
        };
        // {end_time, room_no} to fetch early finishing meeting
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(auto meeting: meetings){
            int start = meeting[0], end = meeting[1], diff, roomNo;
            
            while(!pq.empty() && pq.top().first <= start){
                freeRoom.push(pq.top().second);
                pq.pop();
            }
            
            // if free room are availabel
            if(!freeRoom.empty()){
                roomNo = freeRoom.top();
                freeRoom.pop();
                pq.push({end, roomNo});
                meetingsCount[roomNo] += 1;
            }
            // if not there will be delay in meeting and has to wait for other rooms 
            else{
                diff = pq.top().first + end - start;
                roomNo = pq.top().second;
                pq.pop();
                pq.push({diff, roomNo});
                meetingsCount[roomNo] += 1;
            }
        }
        // ans will be calculated based on the frequency
        int res = 0, maxCount = 0;
        for(int i=0; i<n; ++i){
            if(meetingsCount[i] > maxCount){
                maxCount = meetingsCount[i];
                res = i;
            }
        }
        return res;
    }
};