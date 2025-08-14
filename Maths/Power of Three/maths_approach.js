
//Time complexity :- O(log3(n))
//Space complexity :- O(1)


//link :- https://leetcode.com/problems/power-of-three/

var isPowerOfThree = function(n) {
    if(n <= 0)  return false;
    while(n%3 == 0)
        n/=3;
    return n == 1;
};