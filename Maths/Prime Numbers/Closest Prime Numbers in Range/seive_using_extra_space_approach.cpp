#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(right)
// Space complexity :- O(right + right)

// Approach :-
// for finding prime number we can use seive method and maximum number will be right 
// store all the prime number in an array (arr)
// Traverse on the arr's adjacent element and calculate the answer base on the difference of number

// Link :- https://leetcode.com/problems/closest-prime-numbers-in-range/


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> seive(right+1, -1), arr, res(2);

        for(int i=2; i<=right; ++i)
            seive[i] = i;
        
        for(int i=2; i*i<=right; i++){
            if(seive[i] == i){
                for(int j=i*i; j<=right; j+=i)
                    seive[j] = i;
            }
        }
        for(int i=left; i<=right; ++i){
            if(seive[i] == i)
                arr.push_back(i);
        }
        int n = arr.size();
        if(n < 2){
            res[0] = -1;
            res[1] = -1;
        }else{
            res[0] = arr[0];
            res[1] = arr[1];
            for(int i=1; i<n-1; ++i){
                if((arr[i+1]-arr[i]) < (res[1]-res[0])){
                    res[0] = arr[i];
                    res[1] = arr[i+1];
                }
            }
        }
        return res;
    }
};