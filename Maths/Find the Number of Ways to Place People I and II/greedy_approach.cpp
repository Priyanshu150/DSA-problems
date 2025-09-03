#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^2 + n*log(n))
// Space complexity :- O(1)

// Approach :- 
// Sort all the value of coordinate on x-cord using custome sorting technique 
// if both x-cord are matching then sort in terms of y which is having larger y-cord 
// that way we can handle one of the corner case (1,1) and (1,3)
// (x2 >= x1) and (y1 >= y2), first condition is sorted 
// for second condition we'll traverse on the right side of current cord
// and maintain maxY cord to  check wheather any point is lying in the rectangle or not 
// because all the point b/w two x-cord should lie either below or above the rectangle 
// if(y2 > y1) then it's not possible 
// if(maxY < y2) then it's possible then y2 = maxY and increment 1 count of res

// Link :- 
// I - https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/
// II- https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), res = 0;

        auto lambda = [](vector<int> &point1, vector<int> &point2){
            if(point1[0] == point2[0])
                return point1[1] > point2[1];
            
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lambda);

        for(int i=0; i<n; ++i){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int maxY = INT_MIN;

            for(int j=i+1; j<n; ++j){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1)    continue;

                if(y2 > maxY){
                    res++;
                    maxY = y2;
                }
            }
        }
        return res;
    }
};