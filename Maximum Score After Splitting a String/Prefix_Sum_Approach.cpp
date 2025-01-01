#include<bits/stdc++.h>
using namespace std;

//Time Complexity :- O(N)
//Space Complexity :- O(1)

class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ones = 0, zeros = 0, res = 0;
        if(s[0] == '0')     zeros++;    //for non-empty array left part
        
        //prefix sum calulation of '1' on the right side
        for(int i=1; i<n; ++i){
            if(s[i] == '1')
                ones++;
        }
        res = max(res, ones + zeros);
        
        // Calulation of '0' on the left subarray and '1' on right subarray for all the combination
        for(int i=1; i<n-1; ++i){
            if(s[i] == '1')
                ones--;
            else if(s[i] == '0')
                zeros++;
            
            res = max(res, ones + zeros);
        }
        return res;
    }
};