#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(V+E)
// Space complexity :- O(words.length*each_word_length + V+E)

// Approach :-
// Using the words given create a directed graph on based on the logic
// that 2 words differ at a index then, for ex those char are a & b then we can say that a -> b has a edge
// after creating the graph apply khans algorithm to get the order
// The order will not exist 1) if there is cyclic dependency and
// 2) greater string appear before smaller string and they both differ by only 1 char
// which is present at the last i.e. [abc, ab]


// Links :- https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;
        string prevWord = "", res = "";
        
        for(auto word: words){
            int n = word.size(), m = prevWord.size();
            
            for(int i=0; i<n; ++i){
                if(!inDegree.count(word[i]))
                    inDegree[word[i]] = 0;
                
                if(prevWord != "" && i<m && prevWord[i] != word[i]){
                    m = 0;
                    graph[prevWord[i]].push_back(word[i]);
                    inDegree[word[i]] += 1;
                }
            }
            if(m > n)   return "";
            prevWord = word;
        }
        queue<char> q;
        
        for(auto it: inDegree){
            char nd = it.first;
            int inDeg = it.second;
            if(inDeg == 0)
                q.push(nd);
        }
        
        while(!q.empty()){
            char nd = q.front();
            q.pop();
            
            res += nd;
            
            for(auto ngr: graph[nd]){
                inDegree[ngr] -= 1;
                if(inDegree[ngr] == 0)
                    q.push(ngr);
            }
        }
        return (res.size() == inDegree.size()) ? res : "";
    }
};