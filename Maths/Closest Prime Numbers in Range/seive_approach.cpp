#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(right)
// Space complexity :- O(right)

// Approach :-
// for finding prime number we can use seive method and maximum number will be right 
// use two pointers first and second to find and traverse on seive array 
// such that first & second point to prime numbers respectively such that second > first
// update the answer accordingly based on different b/w these two numbers 

// Link :- https://leetcode.com/problems/closest-prime-numbers-in-range/

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> seive(right+1, -1), res(2, -1);
        res[1] = 1e7;

        for(int i=2; i<=right; ++i)
            seive[i] = i;
        
        for(int i=2; i*i<=right; i++){
            if(seive[i] == i){
                for(int j=i*i; j<=right; j+=i)
                    seive[j] = i;
            }
        }
        int first = left;
        while(first <= right && seive[first] != first)
            first++;

        while(first <= right){
            int second = first+1;
            
            while(second <= right && seive[second] != second)
                second++;
            
            if(second <= right && (second - first) < (res[1] - res[0])){
                res[0] = first;
                res[1] = second;
            }
            first = second;
        }
        if(res[1] == 1e7)   res[1] = -1;
        return res;
    }
};