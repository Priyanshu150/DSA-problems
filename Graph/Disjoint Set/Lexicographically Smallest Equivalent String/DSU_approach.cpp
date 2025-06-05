#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + m)
// Space complexity :- O(26)

// Approach :- 
// we'll use a data strucuture to store the equivalence relation 
// and each char is pointing to lexiographically smallest string
// Disjoint set can be used to maintain such relation and parent array within it will be our DS to store relation
// traverse in string s1 and s2 and form the relation using DSU
// traverse on baseStr and for a resultant stirng by finding the parent of curr_char which will be lexigraphically smallest


// Link :- https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

class DisjointSet{
  private:
    vector<int> parent;

  public:
    DisjointSet(int node){
        parent.resize(node+1);

        for(int i=0; i<=node; ++i)
            parent[i] = i;
    }
    
    int findParent(int node){
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    void unionNodes(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v)
            return;
        
        if(ulp_u < ulp_v){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet graph(26);
        int n = s1.size(), m = baseStr.size();

        for(int i=0; i<n; ++i){
            graph.unionNodes(s1[i]-'a', s2[i]-'a');
        }
        string res = "";

        for(int i=0; i<m; ++i){
            int par = graph.findParent(baseStr[i] - 'a');
            res += ('a' + par);
        }
        return res;
    }
};