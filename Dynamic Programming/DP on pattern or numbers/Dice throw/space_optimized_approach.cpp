#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*m*x)
// Space complexity :- O(x)

// Approach :- 
// Instead of using a 2-d dp we can use 2 array which decreases the space 
// since we're only using curr and previous array so it'll be logical


// Link :- https://www.geeksforgeeks.org/problems/dice-throw5349/1

class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<int> ahead(x+1, 0), curr(x+1, 0);
        ahead[0] = 1;
        
        for(int diceCnt=n-1; diceCnt>=0; --diceCnt){
            fill(curr.begin(), curr.end(), 0);
            
            for(int sum=1; sum<=x; ++sum){
                for(int faceVal=1; faceVal<=m; ++faceVal){
                    if(sum - faceVal >= 0){
                        curr[sum] += ahead[sum - faceVal];
                    }
                }
            }
            ahead = curr;
        }
        return ahead[x];
    }
};
