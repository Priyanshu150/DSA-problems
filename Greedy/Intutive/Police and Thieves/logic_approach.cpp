#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(1)

// Approach :- 
// maintain the two pointer pointer which is pointing to police index and theif index respectively
// if they are range increase the index and count them as 1 answer
// other if theif_ind < police_ind then increase the theif_ind otherwise vice-versa
// which indicates that these index are out of limit 


// Link :- https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size(), cnt = 0;
        int police = 0, theif = 0;
        
        while(police < n && arr[police] != 'P')
            ++police;
            
        while(theif < n && arr[theif] != 'T')
            ++theif;
        
        while(police < n && theif < n){
            if(abs(police - theif) <= k){
                cnt++;
                police++;
                theif++;
            }
            else if(theif < n && theif < police)
                theif++;
            else if(police < n && police < theif)
                police++;
            
            while(police < n && arr[police] != 'P')
                ++police;
            
            while(theif < n && arr[theif] != 'T')
                ++theif;
        }
        return cnt;
    }
};