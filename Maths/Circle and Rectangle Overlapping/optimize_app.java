import java.util.*;

//Time complextiy :- O(1)
// Space complexity :- O(1)

// Approach :- 

//Link :- https://leetcode.com/problems/circle-and-rectangle-overlapping/description/


class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearX = Math.clamp(xCenter, x1, x2);
        int nearY = Math.clamp(yCenter, y1, y2);

        int dx = nearX - xCenter;
        int dy = nearY - yCenter;
        return (dx * dx + dy * dy) <= (radius * radius);
    }
}