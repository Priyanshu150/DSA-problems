#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n)

// Approach :-
// Count the sum of digit of each number, and store it in the map
// In map we'll store for each sum of digit what is the count of numbers 
// while caluclate the sum we'll also maintain the the maximum count of number for a particular digit sum
// at last traverse the map and count the number of sum_of_digit which has the size equal to largest size


//link :- https://www.geeksforgeeks.org/problems/find-unique-number/1

class Solution {
public:
    int countLargestGroup(int n) {
        int largestSize = 0, res = 0;
        unordered_map<int,int> mp;

        for(int num=1; num<=n; ++num){
            string str = to_string(num);
            int sum = 0;

            for(auto ch: str)
                sum += (ch - '0');
            
            mp[sum] += 1;
            largestSize = max(mp[sum], largestSize);
        }
        for(auto [num, sz]: mp){
            if(largestSize == sz)
                res += 1;
        }
        return res;
    }
};