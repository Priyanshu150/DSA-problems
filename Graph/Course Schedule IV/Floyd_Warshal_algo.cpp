#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// Imagine if the courses are nodes of a graph. We need to build an array isReachable[i][j].
// Start a bfs from each course i and assign for each course j you visit isReachable[i][j] = True.
// Answer the queries from the isReachable array.
// We can use floyd warshall algorithm to create the isReachable array

//Link :- https://leetcode.com/problems/course-schedule-iv/description/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> isReachable(numCourses, vector<int> (numCourses, INT_MAX));

        for(int i=0; i<numCourses; ++i)
            isReachable[i][i] = 0;

        for(auto edge: prerequisites)
            isReachable[edge[0]][edge[1]] = 1;

        for(int k=0; k<numCourses; ++k){
            for(int i=0; i<numCourses; ++i){
                for(int j=0; j<numCourses; ++j){
                    if(isReachable[i][k] != INT_MAX && isReachable[k][j] != INT_MAX)
                        isReachable[i][j] = min(isReachable[i][j], 
                                            isReachable[i][k] +isReachable[k][j]);
                }
            }
        }
        vector<bool> ans;
        for(auto query: queries){
            if(isReachable[query[0]][query[1]] != INT_MAX)
                ans.push_back(true);
            else 
                ans.push_back(false);
        }
        return ans;
    }
};