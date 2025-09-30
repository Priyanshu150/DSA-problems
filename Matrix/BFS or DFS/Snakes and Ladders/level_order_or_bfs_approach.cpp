#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
// Space complexity :- O(n*n)

//Approach :- 
// apply bfs and level order traversal to find the shortest time 
// In queue maintain the numbers on which a player is currently present
// from a current possition explore all the options of dice roll from val 1 to 6
// find the row and col using formula, if the value is present at that cell 
// it means that there will be either a ladder or snake take that route
// otherwise the value take next value as current_position + dice_value
// if we reach at n*n return the level number
// After trying all sequence if we're unable to reach then reutrn -1 stating it's not possible


//Link :- https://leetcode.com/problems/snakes-and-ladders/

class Solution {
private:
    pair<int,int> coordinates(int x, int n){
        int r = n-(x-1)/n-1;
        int c = (x-1)%n;

        if(r%2==n%2)
            return {r, n-c-1};
        
        return {r,c};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int res = 0, n = board.size();
        queue<int> q; 
        q.push(1);
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vis[n-1][0] = true;

        while(!q.empty()){
            int sz = q.size();

            while(sz-- > 0){
                int val = q.front();
                q.pop();

                if(val == n*n)
                    return res;
                
                for(int dice=1; dice<=6; ++dice){
                    int next = min(val + dice, n*n);
                    auto [row, col] = coordinates(next, n);

                    if(vis[row][col] == true)
                        continue;
                    
                    vis[row][col] = true;
                    
                    if(board[row][col] != -1)
                        q.push(board[row][col]);
                    else 
                        q.push(next);
                }
            }
            ++res;
        }
        return -1;
    }
};