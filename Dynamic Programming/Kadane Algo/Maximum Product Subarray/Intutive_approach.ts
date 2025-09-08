#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach :- 
// Here the some observation for this problem 
// 1. When all +ve then product of array will be the answer
// 2. when odd number of -ve element then either prefix before -ve element or after it will have the max product
// 3. when even number of -ve element then all the array product is answer 
// 4. whenever zeros comes, the array should be divided such we find answer in different subarrays splitted by 0s
// Hence, we'll find the product of each suffix and prefix element and maintain a max product for our answer
// this approach also shares the same concept as kadanes algo

// Link :- https://leetcode.com/problems/maximum-product-subarray/

function maxProduct(nums: number[]): number {
    let res: number = -Infinity;
    let n: number = nums.length;
    let prefix: number = 1, suffix: number = 1; 

    for(let i: number = 0; i<n; ++i){
        prefix = ((prefix === 0) ? 1 : prefix)*nums[i];
        suffix = ((suffix === 0) ? 1 : suffix)*nums[n-i-1];
        res = Math.max(res, prefix, suffix);
    }
    return res;
};