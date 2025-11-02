#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(1)
//Space complexity :- O(1)

// Approach :-
// the result will be difference b/w 
// total number of edge a graph can have and number of edge present in given graph
// we can change the edge accordingly to form a DAG hence no need to check ever edge 


//link :- https://www.geeksforgeeks.org/problems/max-dag-edges/1

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int totalEdge = (V*(V-1))/2;
        int edgePresent = edges.size();
        return totalEdge - edgePresent;
    }
};

