#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n^3)  
// Space complexity :- O(n)

// Approach :-
// Choose 3 indexes using 3 loops, which should not be equal and first element not 0
// form a number using these 3 number and hash it and build answer


// Link :- https://leetcode.com/problems/finding-3-digit-even-numbers/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;

        for(int i=0; i<n; ++i){
            if(digits[i] == 0)    continue;

            for(int j=0; j<n; ++j){
                if(i == j)  continue;

                for(int k=0; k<n; ++k){
                    if(k == i || k == j)    continue;

                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num % 2 == 0)
                        st.insert(num);
                }
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        unordered_set<int> st;

        for(int i=0; i<n; ++i){
            if(digits[i] == 0)    continue;

            for(int j=0; j<n; ++j){
                if(i == j)  continue;

                for(int k=0; k<n; ++k){
                    if(k == i || k == j)    continue;

                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num % 2 == 0 && !st.count(num)){
                        ans.push_back(num);
                        st.insert(num);
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<bool> isPresent(905, false);

        for(int i=0; i<n; ++i){
            if(digits[i] == 0)    continue;

            for(int j=0; j<n; ++j){
                if(i == j)  continue;

                for(int k=0; k<n; ++k){
                    if(k == i || k == j)    continue;

                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    isPresent[num - 100] = true;
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<905; ++i){
            if(isPresent[i] and (i&1) == 0)
                ans.push_back(i+100);
        }
        return ans;
    }
};