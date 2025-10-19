#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*n)
// Space complexity :- O(10*n*n)

// Approach :-  
//  using bfs try explore possibilites and maintain the lexiographicall smallest string as answer


// links :- https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

class Solution {
private:
    void rotate(string &s, int &b){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+b);
        reverse(s.begin()+b, s.end());
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        queue<string> q;
        unordered_set<string> vis;
        string res = s;

        q.push(s);
        vis.insert(s);

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr < res)
                res = curr;
            
            // add a to odd index of string 
            for(int i=1; i<n; i+=2){
                curr[i] = ((((curr[i] - '0') + a) % 10) + '0');
            }
            if(!vis.count(curr)){
                q.push(curr);
                vis.insert(curr);
            }

            // rotate string by b times 
            rotate(curr, b);
            if(!vis.count(curr)){
                q.push(curr);
                vis.insert(curr);
            }
        }
        return res;
    }
};