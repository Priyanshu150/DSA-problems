
// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach :- 
// Extending the capability of kadane's algo 
// At each index i, we maintain:
// maxProd → maximum product subarray ending at i
// minProd → minimum product subarray ending at i
// (because multiplying a big negative with a negative number can become the new maximum)

// Link :- https://leetcode.com/problems/maximum-product-subarray/

function maxProduct(nums: number[]): number {
    let n: number = nums.length
    let res: number = nums[0]
    let maxProd: number = nums[0]
    let minProd: number = nums[0]

    for(let i: number = 1; i<n; ++i){
        let curr: number = nums[i];
        let tempMax: number = maxProd;

        maxProd = Math.max(curr, maxProd*curr, minProd*curr);
        minProd = Math.min(curr, tempMax*curr, minProd*curr);

        res = Math.max(maxProd, res);
    }
    return res;
};