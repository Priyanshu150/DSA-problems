#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(log(b))
// Space complexity :- O(log(b))              

// Approach :- 
// whenever the power is odd the result will a^(b/2) * a
// when it's even the result will be a^(b/2)
// iterative calculate the result until b becomes 0, divide b by 2 until it becomes 0
// a will be equal to a*a
// whenever the b==1 or b is odd, calculate the result res = (a*res)


// Links :- https://leetcode.com/problems/powx-n/description/

ll binaryExponentiation(ll a, ll b){
    if(b == 0)      return 1;
    if(b == 1)      return a;

    ll ans = binaryExponentiation(a, b/2) % mod;
    ans = (ans*ans)%mod;

    if(b%2)     ans = (ans*a)%mod;
    return ans;
}  
