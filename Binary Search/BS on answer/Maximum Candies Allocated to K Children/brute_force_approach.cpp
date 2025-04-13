#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*N)  
// Space complexity :- O(1)

// Approach :-
// At max the highest chocolate that a childer can get will be max_element of the array
// we can loop from max_element till 1 and check wheather k are allocated to children or not using that number
// A function can be created to check the same
// In the function we can loop on all the candies and caluate the count of sub-grp which we can form
// for count the subgroup we can take (candy / maxCandy) which will gives us valid sub-grp
// if cnt >= k then that will be valid grp return true 
// otherwise if not found after traversing whole array return false

// Link :- https://www.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
private:
    int isPossible(int maxCandy, vector<int>& candies, long long k){
        long long cnt = 0;

        for(auto candy: candies){
            cnt += (candy/maxCandy);
            if(cnt >= k)
                return true;
        }
        return false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int st=1, end = *max_element(candies.begin(), candies.end());

        while(st <= end){
            int mid = st + (end - st)/2;
            if(isPossible(mid, candies, k))         st = mid+1;
            else                                    end = mid-1;
        }
        return end;
    }
};


class Solution {
private:
    int isPossible(int maxCandy, vector<int>& candies, long long k){
        long long cnt = 0;

        for(auto candy: candies){
            cnt += (candy/maxCandy);
            if(cnt >= k)
                return true;
        }
        return false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int st=1, end = *max_element(candies.begin(), candies.end()), res = 0;

        while(st <= end){
            int mid = st + (end - st)/2;
            if(isPossible(mid, candies, k)){
                res = mid;
                st = mid+1;
            }
            else        end = mid-1;
        }
        return res;
    }
};