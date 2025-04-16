#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(min(N, M))
//Space complexity :- O(1)    

//Approach :- 
// Traverse both the arrays simultaneously and collect the same element

//Links :- https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size(), i(0), j(0);
    vector<int> ans;
    
    while(i<n && j<m){
        while(i<n && A[i]<B[j])
            i++;
        
        while(j<m && B[j]<A[i])
            j++;
        
        if(i<n && j<m && A[i] == B[j]){
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}