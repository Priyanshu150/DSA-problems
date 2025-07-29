#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n + 26)  
// Space complexity :- O(n + 26)

// Approach :- 
// store the first and last occurence of each char using hashing 
// maintain a prefix sum array of the whole array using asking value 
// use hashed first and last occurence of each char to calculate the result value 


// Link :- https://www.geeksforgeeks.org/problems/ascii-range-sum/1

class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n = s.size(), sum = 0;
        vector<int> firstOcc(26, -1), lastOcc(26, -1), preSum(n+1, 0), ans;
        
        for(int i=0; i<n; ++i){
            if(firstOcc[s[i]-'a'] == -1)
                firstOcc[s[i]-'a'] = i;
            
            lastOcc[s[i]-'a'] = i;
            sum += s[i];
            preSum[i+1] = sum;
        }
        for(int i=0; i<26; ++i){
            if(firstOcc[i] != lastOcc[i]){
                int sum = preSum[lastOcc[i]] - preSum[firstOcc[i]+1];
                if(sum > 0)     ans.push_back(sum);
            }
        }
        return ans;
    }
};