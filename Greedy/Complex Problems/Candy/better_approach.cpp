#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// Traverse the left to right in the rating array and assign the candies 
// based on the condition ratings[i-1] < rating[i], then candie[i] = candies[i-1]
// repeat the same from right to left, but this time take maximum so that is satifies both condition
// candies[i] will be max(prev_val of candies[i], 1 + candies[i+1])


//Link :- https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), sum=0;
        vector<int> left(n, 1);

        for(int i=1; i<n; ++i){
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1]+1;
        }

        for(int i=n-2; i>=0; --i){
            if(ratings[i+1] < ratings[i])
                left[i] = max(left[i], 1+left[i+1]);
        }
        
        sum = accumulate(begin(left), end(left), sum);
        return sum;
    }
};