#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// traverse on the string from left to right, and count the contribution of each dirs
// for find the maximum distance from origin it will be depend on 
// abs(north - south) + abs(east - west), we've to maximize each of them
// by counting we'll know how many contribution both north and south has 
// which has the least contribution can be converted to other direction to increase the count
// keeping k in the concept not exceeding count from that 
// similar can be done from east-west direction if k is left 


// Link :- https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/

class Solution {
private:
    void changeDirections(int &dir1, int &dir2, int &k){
        if(k == 0)      return;

        if(dir1 >= dir2){
            if(dir2 >= k){
                dir1 += k;
                dir2 -= k;
                k = 0;
            }
            else{
                dir1 += dir2;
                k -= dir2;
                dir2 = 0;
            }
        }
        else{
            if(dir1 >= k){
                dir2 += k;
                dir1 -= k;
                k = 0;
            }
            else{
                dir2 += dir1;
                k -= dir1;
                dir1 = 0;
            }
        }
    }

    int calculateDist(int nt, int st, int wt, int et, int k){
        changeDirections(nt, st, k);
        changeDirections(et, wt, k);
        return abs(nt - st) + abs(et - wt);
    }

public:
    int maxDistance(string s, int k) {
        int nt = 0, st = 0, wt = 0, et = 0, res = 0;

        for(auto ch: s){
            if(ch == 'N')   nt++;
            else if(ch == 'S')  st++;
            else if(ch == 'E')  et++;
            else    wt++;
            
            int dist = calculateDist(nt, st, wt, et, k);
            res = max(res, dist);
        }
        return res;
    }
};