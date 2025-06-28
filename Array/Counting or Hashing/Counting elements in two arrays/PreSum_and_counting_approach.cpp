#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + m + 1e5+1)  
// Space complexity :- O(1e5+1)

// Approach :-  
// maintain a freq array for array2 and count the number each element ans store them
// using that array count the presum of the frequency array 
// for every number in array1, check the frequency array to find the actual count 


// Link :- https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        const int size = 1e5+1;
        vector<int> ans, preCnt(size, 0);
        
        for(auto num: b)
            preCnt[num] += 1;
        
        for(int i=1; i<size; ++i)
            preCnt[i] += preCnt[i-1];
        
        for(auto num: a)
            ans.push_back(preCnt[num]);
        
        return ans;
    }
};