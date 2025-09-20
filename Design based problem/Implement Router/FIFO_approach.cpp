#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(log(n))
// Space complexity :- O(N)

// Approach :-  
// use queue to store packet for FIFO property 
// use map to store the information of packet, packetStore; // key -> {src, dest, time}
// use map to store for a given destination all the timestamp a router is holding,  destTimeStamp;  // dest -> {t1, t2, t3}

// In addPacket, 
// form a string using property, if duplicate exist return, if the queue is full remove 1 from starting
// and then insert the packet into the respective ds 
// In forWardPacket function, 
// find the starting packet from the queue and remove it from all the ds 
// In getCount function, 
// check on the destination provided in map and using lower and upper bound find the occurence of the time 
// which are lieing in the range b/w startTime and endTime 

// links :- https://leetcode.com/problems/implement-router/

class Router {
private:
    int size;
    queue<string> q;
    unordered_map<string, vector<int> > packetStore; // key -> {src, dest, time}
    unordered_map<int, vector<int> > destTimeStamp;  // dest -> {t1, t2, t3}

public:
    Router(int memoryLimit) {
        // save the max size 
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        // convert the {src, dest, time} into string 
        string packet = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);

        // If packet already exist with the same properties
        if(packetStore.count(packet))
            return false;
        
        // If maxsize is reached removed from start 
        if(q.size() == size)
            forwardPacket();
        

        q.push(packet);
        packetStore[packet] = {source, destination, timestamp};
        destTimeStamp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size() == 0)
            return {};
        
        // get the old packet 
        string packet = q.front();
        q.pop();
    
        vector<int> res = packetStore[packet];
        packetStore.erase(packet);

        int dest = res[1];
        destTimeStamp[dest].erase(destTimeStamp[dest].begin());
        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(!destTimeStamp.count(destination))
            return 0;
        
        vector<int> &temp = destTimeStamp[destination];

        if(temp.empty())        return 0;

        int lb = lower_bound(temp.begin(), temp.end(), startTime) - temp.begin();
        int ub = upper_bound(temp.begin(), temp.end(), endTime) - temp.begin();
        return (ub - lb);
    }
};
