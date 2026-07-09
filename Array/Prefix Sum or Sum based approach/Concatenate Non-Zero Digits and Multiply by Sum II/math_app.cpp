#include<bits/stdc++.h>

//Time complextiy :- O(m + q)
// Space complexity :- O(m)

// Approach :-  
// for sum, we can directly use prefix sum method on the array 
// for number, we can maintain the number till every index excluding 0
// whenever there is a need to find number of sub-range (1234 - 1200 = 34) 
// number till current right index is 1234 and till left-1 is 12 then we've to multiply 10^k * 12 
//  then substract it with the current index number to get our number 
// where k will be the number of digit found b/w left and right index 
// which can be also maintained using presum on digit approach 
// we can also store the power of 10 instead of re-calculating it 

//Link :- https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/

class Solution {
private:
    typedef long long ll;

    ll mod = 1e9+7;

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<ll> powerOf10;
        powerOf10.push_back(1);

        // pre calculate the power of 10 till 10^m
        for(int i=0; i<m; ++i){
            ll val = (powerOf10[i] * 10) % mod;
            powerOf10.push_back(val);
        }
        
        vector<ll> preSum, digitCount, number;
        ll sum = 0, digits = 0, num = 0;

        // traverse on the string
        for(int i=0; i<m; ++i){
            // find the digit at current char
            int digit = s[i] - '0';
            // maintain the sum using digit 
            sum = (sum + digit) % mod;
            preSum.push_back(sum);      // add the sum till index in preSum array 
            
            // if digit is greater than 0
            if(digit > 0){
                // digit count will increase 
                digits += 1;
                // new number will be update at 1's place 
                num = (num*10 + digit) % mod;
            }
            // update both count into the repsective ds
            digitCount.push_back(digits); 
            number.push_back(num);
        }
        vector<int> ans;

        // for every query
        for(auto query: queries){
            int left = query[0], right = query[1];

            // find the sum, digit count, number till the current index 
            ll sum = preSum[right] % mod;
            ll k = digitCount[right] % mod;
            ll num = number[right] % mod;

            // if left index is greater than 0
            if(left > 0){
                // subtract [left-1] sum from the overall sum
                sum = ((sum - preSum[left-1]) % mod + mod) % mod;
                // subtract [left-1] digit from the overall digit 
                k   = digitCount[right] - digitCount[left-1];
                // find the new number 
                ll prev = ((number[left-1] % mod) * (powerOf10[k] % mod)) % mod;
                num = ((num - prev) % mod + mod) % mod;
            }
            // update the answer into the array 
            ll result = (sum * num) % mod;
            ans.push_back(result);
        }
        return ans;
    }
};