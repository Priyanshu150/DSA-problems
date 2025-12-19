#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(m*(n+m))
//Space complexity :- O(n+m) 

// Approach :-

//link :- https://leetcode.com/problems/find-all-people-with-secret/

class Solution {
private:
    typedef pair<int,int> pii;

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pii>> timeToMeet; // time -> {{p1, p2}, {p1, p3}}

        // create time to person mapping on sorted order 
        for(auto meet: meetings){
            int person1 = meet[0];
            int person2 = meet[1];
            int time = meet[2];

            timeToMeet[time].push_back({person1, person2});
        }
        
        vector<int> personKnows(n, false);
        // person 0 tell firstPerson the secret 
        personKnows[0] = true;
        personKnows[firstPerson] = true;

        for(auto it: timeToMeet){
            int time = it.first;
            vector<pii> meets = it.second;
            
            vector<vector<int>> graph(n);
            // build the graph
            for(auto meet: meets){
                int u = meet.first, v = meet.second;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            // standard bfs 
            queue<int> q;

            for(int i=0; i<n; ++i){
                if(personKnows[i] == true){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto adjNd: graph[node]){
                    if(personKnows[adjNd] == false){
                        q.push(adjNd);
                        personKnows[adjNd] = true;
                    }
                }
            }
        }

        vector<int> res;
        // check which person knows the secret 
        for(int i=0; i<n; ++i){
            if(personKnows[i] == true){
                res.push_back(i);
            }
        }
        return res;
    }
};  