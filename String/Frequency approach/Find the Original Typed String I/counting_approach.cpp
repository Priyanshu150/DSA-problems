#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :-  
// Any group of continuous character might have been a mistake 
// count all the continuous character if they are greater than 1 
// then add them into the answer by subtracting 1 from the count 
// because if we take all the frequency it'll give us the given string 
// again and again for all the mistyped word 
// and that count of string will be redundant in our answer 


// links :- https://leetcode.com/problems/find-the-original-typed-string-i/

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1, cnt = 0, n = word.size();

        for(int i=1; i<n; ++i){
            if(word[i] == word[i-1])
                cnt++;
            else{
                res += cnt;
                cnt = 0;
            }
        }
        res += cnt;
        return res;
    }
};
