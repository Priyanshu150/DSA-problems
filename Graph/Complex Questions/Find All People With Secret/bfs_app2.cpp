#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n+m)
//Space complexity :- O(n+m) 

// Approach :-

//link :- https://leetcode.com/problems/find-all-people-with-secret/

class Solution {
private:
    typedef pair<int,int> pii;

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pii>> graph(n);

        // build an unordered graph 
        for(auto meeting: meetings){
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            graph[person1].push_back({person2, time});
            graph[person2].push_back({person1, time});
        }

        vector<int> personKnows(n, INT_MAX);
        // 0 tells the secret to first person at time 0
        personKnows[0] = 0;
        personKnows[firstPerson] = 0;

        queue<pii> q;
        // add source node into the queue 
        q.push({0, 0});
        q.push({firstPerson, 0});

        // standard bfs
        while(!q.empty()){
            pii it = q.front();
            q.pop();
            // current presoon details
            int person = it.first;
            int time = it.second;

            // traverse on the adj node
            for(auto adjNd: graph[person]){
                int anotherPerson = adjNd.first;
                int timeOfMeet = adjNd.second;

                // if meeting time b/w person is less than the time at which person knows the secret then they cannot tell the other person 
                if(timeOfMeet < time)   
                    continue;
                
                // if the time can be minimized 
                if(timeOfMeet < personKnows[anotherPerson]){
                    personKnows[anotherPerson] = timeOfMeet;
                    q.push({anotherPerson, timeOfMeet});
                }
            }
        }
        vector<int> res;
        // check which person knows the secret 
        for(int i=0; i<n; ++i){
            if(personKnows[i] != INT_MAX){
                res.push_back(i);
            }
        }
        return res;
    }
};