#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :-  
// Use sort when performance matters more and you don’t care about the relative order of equal elements.
// Worst TC = O(NlogN)

// Use stable_sort when the original order among equals must be preserved 
//(like sorting people by age but keeping their input order if they’re the same age)
// Worst TC = O(Nlog^2*N)


//Link :- https://www.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1

class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        stable_sort(arr.begin(), arr.end(), [&](int num1, int num2){
            return abs(x - num1) < abs(x - num2);
        });
    }
};