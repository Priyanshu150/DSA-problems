#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)
// Space complexity :- O(1)

// Approach :- 
// apply custom sorting logic 
// when convert the numbers into string and then check the logic 


// Link :- https://leetcode.com/problems/lexicographical-numbers/


class Solution {
private:
    static bool comp(int num1, int num2){
        return to_string(num1) < to_string(num2);
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=n; ++i)
            ans.push_back(i);
        
        sort(ans.begin(),ans.end(), comp);
        return ans;
    }
};  


class Solution {
private:
    static bool comp(int num1, int num2){
        string n1 = to_string(num1);
        string n2 = to_string(num2);
        int sz = min(n1.size(), n2.size());

        for(int i=0; i<sz; ++i){
            if(n1[i] < n2[i])   return true;
            if(n1[i] > n2[i])   return false;
        }
        return (n1.size() < n2.size());
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=n; ++i)
            ans.push_back(i);
        
        sort(ans.begin(),ans.end(), comp);
        return ans;
    }
};