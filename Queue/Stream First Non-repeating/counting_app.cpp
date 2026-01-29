#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N) 

// Approach :-
// Add all the char which has frequency as 1, traversing from left to right 
// for char check which char is present at front of queue 

//link :- https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

class Solution {
  public:
    string firstNonRepeating(string &s) {
        string res = "";
        queue<char> q;              // store the char having non-repeating freq
        int freq[26] = {0};         // for counting the freq of each element 
        
        for(auto ch: s){
            // increment the freq of current char 
            freq[ch - 'a'] += 1;
            
            // remove all the element from the queue which has repeating freq
            while(!q.empty() && freq[q.front() - 'a'] > 1){
                q.pop();
            }
            
            // push the current element into the queue only if it has single freq
            if(freq[ch - 'a'] == 1)
                q.push(ch);
            
            // add the front element to queue or '#' if it's empty 
            if(!q.empty())          res += q.front();
            else                    res += '#';
        }
        return res;
    }
};