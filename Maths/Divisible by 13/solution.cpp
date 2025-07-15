#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// maintain a remainder variable at last if it becomes 0 then it's possible 
// traverse on the string and multiply previous remainder by 10 and add curr_num
// then divide the curr_num by 13 and store the remainder 


// Link :- https://www.geeksforgeeks.org/problems/divisible-by-13/1

class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int rem = 0;
        
        for(auto digit: s){
            rem = rem*10 + (digit - '0');
            rem = (rem % 13);
        }
        return (rem == 0);
    }
};
