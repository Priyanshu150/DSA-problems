#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*log(n))                 
// Space complexity :- O(n+26)              

// Approach :-  
// count the freq of each char and put the freq into array 
// sort the array and apply the approach used in "Coin Piles" problem
// use binary search to calcualte the min answer


// link :- https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0), arr;

        for(auto ch: word)
            freq[ch - 'a'] += 1;
        
        for(int i=0; i<26; ++i){
            if(freq[i] > 0)
                arr.push_back(freq[i]);
        }

        int n = arr.size(), sum = 0, res = INT_MAX;
        sort(arr.begin(), arr.end());
        vector<int> preSum(n+1, 0);

        for(int i=0; i<n; ++i){
            sum += arr[i];
            preSum[i+1] = sum;
        }

        for(int i=0; i<n; ++i){
            int pos = upper_bound(arr.begin()+i, arr.end(), arr[i]+k) - arr.begin();
            int expectedSum = (n-pos)*(arr[i]+k);
            int actualSum = preSum[n] - preSum[pos];
            int deleted = actualSum - expectedSum + preSum[i];
            res = min(res, deleted);
        }
        return res;
    }
};