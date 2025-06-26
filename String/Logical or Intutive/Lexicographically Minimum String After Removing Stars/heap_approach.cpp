#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :- 
// use a customized heap to find the next smallest char on left and use an marked array 
// to mark the char which has been deleted
// traverse the array and form the result which are not either '*' or makred[index] = true


// Link :- https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/

class comp{
    public:
    bool operator()(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first == p2.first)
            return p1.second < p2.second;
        
        return p1.first > p2.first;
    }
};

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> take(n, true);
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        
        for(int i=0; i<n; ++i){
            if(s[i] == '*' && pq.empty())   continue;
            else if(s[i] == '*'){
                take[pq.top().second] = false;
                pq.pop();
                continue;
            }
            pq.push({s[i]-'a', i});
        }
        string res = "";
        
        for(int i=0; i<n; ++i){
            if(take[i] && s[i] != '*')
                res += s[i];
        }
        return res;
    }
};