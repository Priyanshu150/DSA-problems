#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(m*log(n) + n)
//Space complexity :- O(m*log(n)) 

// Approach :-
// Instead of using queue we can use priority_queue in previous option 
// skipping those which are already visited 
// and will mark node visited only when all the adjNd of that node are visited and so on 

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

        priority_queue<pii, vector<pii>, greater<pii> > pq;
        // add source node into the queue 
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vector<bool> vis(n, false);

        // standard bfs
        while(!pq.empty()){
            pii it = pq.top();
            pq.pop();
            // current presoon details
            int person = it.second;
            int time = it.first;

            if(vis[person] == true)
                continue;
            
            vis[person] = true;

            // traverse on the adj node
            for(auto adjNd: graph[person]){
                int nextPerson = adjNd.first;
                int timeOfMeet = adjNd.second;

                // if meeting time b/w person is less than the time at which person knows the secret then they cannot tell the other person 
                if(timeOfMeet < time)   
                    continue;
                
                // if the time can be minimized 
                if(!vis[nextPerson]){
                    pq.push({timeOfMeet, nextPerson});
                }
            }
        }
        vector<int> res;
        // check which person knows the secret 
        for(int i=0; i<n; ++i){
            if(vis[i] == true){
                res.push_back(i);
            }
        }
        return res;
    }
};