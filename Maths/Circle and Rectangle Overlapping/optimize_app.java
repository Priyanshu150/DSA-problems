// Space complexity :- O(1)

// Approach :- 
// 1. Find the nearest point on the rectangle to the center of the circle.
// 2. Calculate the distance between the nearest point and the center of the circle.
// 3. If the distance is less than or equal to the radius of the circle, then the circle and rectangle overlap.

//Link :- https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/

class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearX, nearY;

        if(x1 > xCenter)        nearX = x1;
        else if(x2 < xCenter)   nearX = x2;
        else                    nearX = xCenter;

        if(y1 > yCenter)        nearY = y1;
        else if(y2 < yCenter)   nearY = y2;
        else                    nearY = yCenter;

        int dx = nearX - xCenter;
        int dy = nearY - yCenter;
        return (dx * dx + dy * dy) <= (radius * radius);
    }
}

class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearX = Math.clamp(xCenter, x1, x2);
        int nearY = Math.clamp(yCenter, y1, y2);

        int dx = nearX - xCenter;
        int dy = nearY - yCenter;
        return (dx * dx + dy * dy) <= (radius * radius);
    }
}