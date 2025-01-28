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