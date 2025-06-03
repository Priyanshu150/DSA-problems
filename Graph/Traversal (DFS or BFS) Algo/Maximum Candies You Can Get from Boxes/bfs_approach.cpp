#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2)
// Space complexity :- O(4*n)

// Approach :- 
// Apply bfs put the one in the queue which has status as open or either we find key & box for the same
// main a hash for boxes and keys 
// traverse on the open lock and take the candies and add to a res variable 
// check the keys present in that box if we already have that boxes for the same we push that into queue
// apply similar things for the boxes present 

// Link :- https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        int n = status.size(), res = 0;
        vector<bool> processed(n, false);
        unordered_set<int> boxes, keysFound;

        for(auto box: initialBoxes){
            if(status[box]){
                q.push(box);
                processed[box] = true;
            }
            else
                boxes.insert(box);
        }

        while(!q.empty()){
            int box = q.front();
            q.pop();

            res += candies[box];

            for(int key: keys[box]){
                if(processed[key])
                    continue;
                
                if(boxes.count(key)){
                    processed[key] = true;
                    q.push(key);
                }
                else 
                    keysFound.insert(key);
            }

            for(int boxNum: containedBoxes[box]){
                if(processed[boxNum])
                    continue;
                
                if(status[boxNum] == 1 || keysFound.count(boxNum)){
                    processed[boxNum] = true;
                    q.push(boxNum);
                }
                else 
                    boxes.insert(boxNum);
            }
        }
        return res;
    }
};
