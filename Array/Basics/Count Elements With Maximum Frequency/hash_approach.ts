//Time complextiy :- O(n)
// Space complexity :- O(n)

// Approach :-  
// using map count the number of frequency of each characters 
// using it find all the element having maximum frequency

// links :- https://leetcode.com/problems/count-elements-with-maximum-frequency/

function maxFrequencyElements(nums: number[]): number {
    let maxi = 0, total = 0;
    const mp: Record<number, number> = {};

    for(const num of nums){
        mp[num] = (mp[num] || 0) + 1;

        if(mp[num] > maxi){
            maxi = mp[num];
            total = 0;
        }

        if(mp[num] == maxi)
            total += maxi;
    }
    return total;
};