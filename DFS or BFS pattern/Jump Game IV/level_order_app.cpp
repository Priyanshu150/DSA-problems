#include<bits10_1.h>
using namespace std;

// Time complexity :- O(n)
// Space complexity :- O(n)

// Approach :- 
// since we've to reach at last index with minimum cost then bfs/level order traversal will work
// we can save all the same value indexes under a hash map 
// traverse the adjacent nodes of the current index and clear the index from the map
// clearing the array will make sure we're not traversing it again and again 
// other in worst case even though we're eliminating the repeated traversal through visited array 
// traversal on index of map will be 'n' and overall solution becomes 'n^2'

// Links :- https://leetcode.com/problems/jump-game-iv/description/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        // base case 
        if(n == 1)
            return 0;
        
        unordered_map<int, vector<int>> graph;

        // build graph based on element value 
        for(int i=0; i<n; ++i){
            graph[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        // start from the the first index 
        q.push(0);
        vis[0] = true;
        int dist = 0;

        // standard level-order traversal 
        while(!q.empty()){
            int sz = q.size();

            while(sz-- > 0){
                int ind = q.front();
                q.pop();
                
                // we reached at the last index 
                if(ind == n-1){
                    return dist;
                }
                // add the next index into the graph
                vector<int> &nextIndices = graph[arr[ind]];

                nextIndices.push_back(ind - 1);
                nextIndices.push_back(ind + 1);
                

                // move to next index which has same value ot the current one 
                for(int nextInd: graph[arr[ind]]){
                    if(nextInd >= 0 && nextInd < n && !vis[nextInd]){
                        q.push(nextInd);
                        vis[nextInd] = true;
                    }
                }
                nextIndices.clear();
            }
            ++dist;
        }
        return dist;
    }
};