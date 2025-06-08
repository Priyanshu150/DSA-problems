#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*log(n))
// Space complexity :- O(n)

// Approach :- 


// Link :- https://leetcode.com/problems/lexicographical-numbers/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int currNum = 1;

        for(int i=1; i<=n; ++i){
            res.push_back(currNum);
            if(currNum*10 <= n){
                currNum *= 10;
            }else{
                while(currNum%10 == 9 || currNum == n){
                    currNum /= 10;
                }
                currNum += 1;
            }
        }
        return res;
    }
};