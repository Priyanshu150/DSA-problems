#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(v+e)
//Space complexity :- O(v+e)

// Approach :-
// a ingredient is dependent on other indegredient so the directed graph can be used here
// If a loop exist b/w ingridient then that is not possible to make
// we can use khan's algorithm to detect the loop and calculate the answer at same time 
// Maintain indegree of each node, and make adj graph of the ingredients 
// Apply the kahn's algorithm and find the answer accordingly

//link :- https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string,int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> supply(supplies.begin(), supplies.end());

        for(int i=0; i<n; ++i){
            inDegree[recipes[i]] = 0;

            for(auto ingredient: ingredients[i]){
                if(supply.count(ingredient))
                    continue;
                
                inDegree[recipes[i]] += 1;
                graph[ingredient].push_back(recipes[i]);
            }
        }
        queue<string> q;

        for(auto [recipe, cnt]: inDegree){
            if(cnt == 0)
                q.push(recipe);
        }
        vector<string> ans;

        while(!q.empty()){
            string recipe = q.front();
            q.pop();
            ans.push_back(recipe);

            for(auto next: graph[recipe]){
                inDegree[next] -= 1;
                if(inDegree[next] == 0)
                    q.push(next);
            }
        }
        return ans;
    }
};