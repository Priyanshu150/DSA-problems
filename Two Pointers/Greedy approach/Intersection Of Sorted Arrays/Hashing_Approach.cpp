#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(N + M)
//Space complexity :- O(min(N, M))

//Approach :- 
// Store the element of shortest array in the map
// Traverse the second array and check which element is present in map

//Links :- https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size();
    if(n > m)       return intersect(B, A);
    
    vector<int> ans;
    unordered_map<int,int> mp;
    
    for(auto num: A)
        mp[num] += 1;
    
    for(auto num: B){
        if(mp.count(num) && mp[num]>0){
            ans.push_back(num);
            mp[num] -= 1;
        }
    }
    return ans;
}