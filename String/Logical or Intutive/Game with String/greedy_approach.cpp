#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(N)    

//Approach :-
// Count the freq of each number and put them into a max heap
// take one freq at a time from the top of the and decrease it freq by 1 and put it back
// repeat this k times and finally calculate the result using max heap 

// Link :- https://www.geeksforgeeks.org/problems/game-with-string4100/1

class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        vector<int> freq(26, 0);
        for(auto ch: s)
            freq[ch - 'a'] += 1;
        
        priority_queue<int> pq;
        for(int i=0; i<26; ++i){
            if(freq[i] == 0)    
                continue;
            
            pq.push(freq[i]);
        }
        while(k > 0){
            int num = pq.top();
            pq.pop();
            
            num -= 1;
            pq.push(num);
            k--;
        }
        int res = 0;
        
        while(!pq.empty()){
            int num = pq.top();
            pq.pop();
            
            res += (num * num);
        }
        return res;
    }
};
