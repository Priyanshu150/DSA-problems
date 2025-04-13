#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(log(b))
// Space complexity :- O(1)              

// Approach :- 
// whenever the power is odd the result will a^(b/2) * a
// when it's even the result will be a^(b/2)
// we can use recursion to solve subproblem i.e. b/2 
// base cases will be when b==0 then return 1 and b == 1   then return a


// Links :- https://leetcode.com/problems/powx-n/description/

ll binaryExponentiation(ll a, ll b){
    ll res = 1;

    while(b){
        if(b&1)
            res = (res*a) % mod;
        
        a = (a*a)%mod;
        b /= 2;
    }
    return res;
}  