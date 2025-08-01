#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(1)

// Approach :-
// Every cell of pascal triangle can be expressed with the combination formula
// using logic/math, find a formula b/w previous number and current number of the sequence 
// using that formula express every term of a sequence

// First and last number of sequence will be 1 i.e. for n = 5, 4(C)0 & 4(C)4 
// we'll be starting our sequence from iteration from 1 to n-1
// if we comparet n(C)1 to n(C)2 to n(C)3, on comparing we'll get a formula
// curr_num = (prev_num * (n-i))/i


//link :- https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> ans;
        ans.push_back(1);
        int prev = 1;
        
        for(int i=1; i<n; ++i){
            prev *= (n-i);
            prev /= i;
            ans.push_back(prev);
        }
        return ans;
    }
};