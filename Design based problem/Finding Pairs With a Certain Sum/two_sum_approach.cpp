#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- add -> O(log(n)) and count -> O(len(num1))
// Space complexity :- O(len(num1) + len(num2))

// Approach :-  
// In constructor store a copy of nums2 and maintain a freq hash map of both the arrays 
// in add function, decreament the freq of the index which is given
// and add the value to the index and put it into the map2 or increment the frequency
// IN count function, traverse on the map1 and check if (tot - it.first) is present in the map2 or not 
// if present then multiply frequencies and add it to the answer
// logic :- we're traversing on the map1 in count function because it has smaller length i.e 10^3
// and at most we're making a call of 10^3 to this function the combination of both is less than 10^8
// if we traverse on the map2 it has a length of 10^5 we'll be getting TLE for this 


// links :- https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

class FindSumPairs {
private:
    vector<int> temp;
    unordered_map<int,int> mp1, mp2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto num: nums1)
            mp1[num] += 1;
        
        for(auto num: nums2){
            temp.push_back(num);
            mp2[num] += 1;
        }
    }
    
    void add(int index, int val) {
        mp2[temp[index]] -= 1;
        temp[index] += val;
        mp2[temp[index]] += 1;
    }
    
    int count(int tot) {
        int res = 0;
        for(auto [num, cnt]: mp1){
            int target = tot - num;

            if(target <= 0)      continue;
            if(mp2.count(target)){
                res += (mp2[target]*cnt);
            }
        }
        return res;
    }
};

