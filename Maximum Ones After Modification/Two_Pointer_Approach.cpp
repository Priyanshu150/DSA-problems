#include<bits/stdc++.h>
using namespace std;

//Link(leetcode) :- https://www.interviewbit.com/problems/maximum-ones-after-modification/

//Time complexity :- O(N)       
//Space complexity :- O(1) 

int solve(vector<int> &A, int B) {
    int n = A.size(), j(0), i(0), ones(0), zeros(0), res(0);
    
    while(j < n){
        if(A[j])        ones++;
        else            zeros++;
        
        while(zeros>B && i<=j){
            if(A[i])        ones--;
            else            zeros--;
            i++;
        }
        res = max(res, ones + zeros);
        j++;
    }
    return res;
}

