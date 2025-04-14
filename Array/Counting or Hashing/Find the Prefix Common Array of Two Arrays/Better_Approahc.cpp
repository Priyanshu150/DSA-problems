#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)
//Space complexity :- O(N)    

//Approach :-
//Consider keeping a frequency array that stores the count of occurrences of each number till index i
//If a number occurred two times, it means it occurred in both A and B since they’re both permutations so add one to the answer

//link :- https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<int> res(n, 0), hash(n+1, 0);

        for(int i=0; i<n; ++i){
            hash[A[i]] += 1;
            if(hash[A[i]] == 2)     cnt++;

            hash[B[i]] += 1;
            if(hash[B[i]] == 2)     cnt++;

            res[i] = cnt;
        }
        return res;
    }
};