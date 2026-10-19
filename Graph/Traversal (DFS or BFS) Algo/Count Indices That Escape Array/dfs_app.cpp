#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach:
// 1. We can use DFS to traverse the array and check if we can escape from each index.
// 2. We will maintain a state array to keep track of the status of each index:
//    - 0 = unvisited
//    - 1 = visiting
//    - 2 = escapes
//    - 3 = does not escape
// 3. For each index, we will perform DFS and check if we can escape from that index.

// Link :- https://www.geeksforgeeks.org/problems/good-stones--170647/1


class Solution {
private:
    int n;

    // 0 = unvisited, 1 = visiting, 2 = escapes, 3 = does not escape
    vector<int> state;

    bool dfs(int node, vector<int>& arr) {
        // The index has escaped the array.
        if (node < 0 || node >= n) {
            return true;
        }

        // Reached a node in the current DFS path: cycle.
        if (state[node] == 1) {
            return false;
        }

        // Reuse previously computed results.
        if (state[node] == 2) {
            return true;
        }

        if (state[node] == 3) {
            return false;
        }

        state[node] = 1;

        long long next = 1LL * node + arr[node];

        bool escapes = (next < 0 || next >= n)
                       ? true
                       : dfs(static_cast<int>(next), arr);

        state[node] = escapes ? 2 : 3;

        return escapes;
    }

public:
    int goodIndices(vector<int>& arr) {
        n = arr.size();
        state.assign(n, 0);

        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, arr)) {
                ++res;
            }
        }

        return res;
    }
};