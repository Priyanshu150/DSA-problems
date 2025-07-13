#include<bits/stdc++.h>
using namespace std;

class Solution {
    #define pii pair<int,int>

public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {0};

        for(auto ch: s)
            freq[ch-'a'] += 1;
        
        priority_queue<pii> pq;

        for(int i=0; i<26; ++i){
            if(freq[i] > 0)
                pq.push({i, freq[i]});
        }
        string res = "";

        while(!pq.empty()){
            pii curr = pq.top();
            pq.pop();

            char ch = 'a' + curr.first;
            int cnt = min(curr.second, repeatLimit);
            res.append(cnt, ch);
            curr.second -= cnt;

            if(curr.second > 0){
                if(pq.empty())      break;

                pii next = pq.top();
                pq.pop();

                res += ('a' + next.first);
                next.second -= 1;

                if(next.second > 0)
                    pq.push(next);

                pq.push(curr);
            }
        }
        return res;
    }
};