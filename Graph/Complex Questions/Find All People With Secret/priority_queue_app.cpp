#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(m*log(n) + n)
//Space complexity :- O(n+m) 

// Approach :-
// Instead of using queue we can use priority_queue in previous option 
// skipping those which are already visited 
// and will mark node visited only when all the adjNd of that node are visited and so on 

//link :- https://leetcode.com/problems/find-all-people-with-secret/

// app1 
class Solution {
private:
    using pii = pair<int,int>; // {time, person}
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pii>> graph(n);

        // build an undirected graph: {neighbor, meetingTime}
        for (auto &m : meetings) {
            int u = m[0], v = m[1], t = m[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        // personKnows[i] = earliest time at which person i knows the secret
        const int INF = INT_MAX;
        vector<int> personKnows(n, INF);
        personKnows[0] = 0;
        personKnows[firstPerson] = 0;

        // min-heap: (time, person)
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        // Dijkstra-like traversal
        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();

            // Outdated entry check
            if (time > personKnows[person]) continue;

            for (auto &[nextPerson, meetTime] : graph[person]) {
                // can only spread secret forward in time
                if (meetTime < time) continue;

                // relax edge: if we can know earlier
                if (meetTime < personKnows[nextPerson]) {
                    personKnows[nextPerson] = meetTime;
                    pq.push({meetTime, nextPerson});
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (personKnows[i] != INF)
                res.push_back(i);
        }
        return res;
    }
};

// app2
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