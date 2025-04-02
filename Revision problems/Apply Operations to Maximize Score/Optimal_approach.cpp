#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n)                  // Where n is number of nodes
// Space complexity :- O(n)                  // n is space for vis arrays and queue

// Approach :-
// We can solve this question by combination of multiple algorithm
// 1. Find the prime factor of each number
// 2. find the number of subarray the current element will contributo to, this can be done using stack
// 3. take a max heap push all pair i.e. value of element and subarray formed by that element 
// 4. Take out the maximum from the top and calucate the res until k becomes 0
// 5. for calculating the power use binary exponentiation 


// Links :- https://leetcode.com/problems/apply-operations-to-maximize-score/

class Solution {
    #define ll long long 
    #define pii pair<ll, ll>
    ll mod = 1e9+7;

private:
    void calculateScore(vector<int> &nums, vector<ll> &score){
        for(ll ele: nums){
            ll count = 0;
            for(ll i=2; i*i<=ele; ++i){
                if(ele%i == 0)
                    count++;
                
                while(ele%i == 0)
                    ele /= i;
            }
            if(ele>1)   count++;
            score.push_back(count);
        }
    }

    void calculateSubarrayCountPerScore(vector<ll> &score, vector<ll> &subarry_count){
        vector<ll> pge;
        stack<ll> st;
        ll n = score.size();

        for(ll i=0; i<n; ++i){
            while(!st.empty() && score[st.top()] < score[i])
                st.pop();
            
            if(st.empty())      pge.push_back(-1);
            else                pge.push_back(st.top());
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        
        ll count;
        for(ll i=n-1; i>=0; --i){
            count = 0;
            while(!st.empty() && score[st.top()] <= score[i])
                st.pop();
            
            if(st.empty())  count = (n-i)*(i-pge[i]);
            else            count = (st.top()-i)*(i-pge[i]);

            st.push(i);
            subarry_count[i] = count;
        }
    }

    ll binaryExponentiation(ll a, ll b){
        ll res = 1;

        while(b){
            if(b&1)     res = (res*a)%mod;

            a = (a*a)%mod;
            b /= 2;
        }
        return res%mod;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        ll n = nums.size(), res = 1;
        vector<ll> score;
        calculateScore(nums, score);

        vector<ll> subarry_count(n);
        calculateSubarrayCountPerScore(score, subarry_count);

        priority_queue<pii> maxHeap;
        for(ll i=0; i<n; ++i)
            maxHeap.push({nums[i], i});

        while(k>0){
            pii curr = maxHeap.top();
            maxHeap.pop();
            res = (res * binaryExponentiation(curr.first, min<ll>(k, subarry_count[curr.second])))%mod;
            k -= subarry_count[curr.second];
        }
        return res;
    }
};