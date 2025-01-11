#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N)       
//Space complexity :- O(1)    

//Approach :-
//Divide array on the basis on region
// 0 to (low-1) -> 0
// low to (mid-1) -> 1
// mid to high -> unknown
// (high+2) to n -> 2
// Traverse from mid to high and sort the value by swapping them to either to low or high
// Intially mid = 0, high = n-1 which is the unknown region

//link :- https://www.interviewbit.com/problems/sort-by-color/

void sortColors(vector<int> &A) {
    int n = A.size(), low = 0, high = n-1, mid = 0;
    
    while(mid <= high){
        if(A[mid] == 0){
            swap(A[low], A[mid]);
            mid++;
            low++;
        }
        else if(A[mid] == 1)    mid++;
        else{
            swap(A[mid], A[high]);
            high--;
        }
    }
}