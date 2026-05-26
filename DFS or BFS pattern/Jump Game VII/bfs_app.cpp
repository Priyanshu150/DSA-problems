#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + n)
// Space complexity :- O(n + n)

// Approach :-  
// we can use bfs traversal to reach the end first based on the index 
// we'll use the logic to find the valid pointer and add it to the queue for traversal 
// use fatherst index to keep track of farthest we've traversed to avoid visiting index again 

// Link :-  https://leetcode.com/problems/jump-game-vii/description/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<bool> vis(n, false);
        vis[0] = true;

        int farthest = 0;

        while(!q.empty()) {
            int ind = q.front();
            q.pop();

            if(ind == n - 1)
                return true;

            int left = max(ind + minJump, farthest + 1);
            int right = min(ind + maxJump, n - 1);

            for(int i = left; i <= right; ++i) {
                if(s[i] == '0' && !vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }

            farthest = right;
        }

        return false;
    }
};