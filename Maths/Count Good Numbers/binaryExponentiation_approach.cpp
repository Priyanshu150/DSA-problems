#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(log(b))
// Space complexity :- O(1)              

// Approach :- 
// we've to fill n place, where every even index should have even no i.e 5 ways (0, 2, 4, 6, 8)
// and odd position should have odd number i.e. 4 ways (2,3,5,7)
// if n is divislbe by 2 then we have to caluclate pow(5, n/2) * pow(4, n/2)
// if n is not divislbe by 2 then we have to caluclate pow(5, n-n/2) * pow(4, n/2)
// in case of not divisible one one more even place exist that's why reminder should be added
// binary exponential can be use to calcalte the power 


// Links :- https://leetcode.com/problems/count-good-numbers/

class Solution {
    #define ll long long
private:
    ll mod = 1e9+7;

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

public:
    int countGoodNumbers(long long n) {
        return binaryExponentiation(4, n/2) * binaryExponentiation(5, n-n/2) % mod;
    }
};