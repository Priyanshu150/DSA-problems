#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^3)
// Space complexity :- O(1)

// Approach :- 
// choose 2 points and check wheather they one is lying on the left-upper and other bottom-right
// and check for every other point wheather they are lying inside the rectangle of formed by these 2 points
// if no point are present then they form a valid points 

// Link :- 
// I - https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/
// II- https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), cnt = 0;
        
        for(int i=0; i<n; ++i){
            int xc = points[i][0], yc = points[i][1];
            for(int j=0; j<n; ++j){
                int xt = points[j][0], yt = points[j][1];
                if(xt == xc && yt == yc)    continue;
                
                if((xc <= xt) && (yt <= yc)){
                    bool flag = true;
                    if(n == 2)      return 1;
                    for(int k=0; k<n; ++k){
                        if(xc == points[k][0] && yc == points[k][1])         continue;
                        else if(xt == points[k][0] && yt == points[k][1])    continue;
                        else if(xc <= points[k][0] && points[k][0] <= xt && yt <= points[k][1] && points[k][1] <= yc)
                            flag = false;
                    }
                    if(flag)    cnt += 1;
                }
            }
        }
        return cnt;
    }
};