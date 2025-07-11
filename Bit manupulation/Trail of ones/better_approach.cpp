#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(2^N)
// Space complexity :- O(2^N)

// Approach :-  
// generate every sequence using bfs techique
// while sotring the sequence store only the last bit of the sequence 
// when the last bit is 1 and we've to add 1 to create next sequence then that will be string that we need
// so it will form 2^(left numbers) of sequences if created further add that to our answer
// and not push taht sequence into the queue, it 'll also prune some branch 


// links :- https://www.geeksforgeeks.org/problems/trail-of-ones3242/1

class Solution {
  public:
    int countConsec(int n) {
        // code here
        int res = 0;
        queue<int> q;
        
        q.push(0);
        q.push(1);
        
        for(int i=1; i<n; ++i){
            int sz = q.size();
            while(sz--){
                int bit = q.front();
                q.pop();
                
                if(bit == 0){
                    q.push(0);
                    q.push(1);
                }
                else{
                    res += (1<<(n-i-1));
                    q.push(0);
                }
            }
        }
        return res;
    }
};