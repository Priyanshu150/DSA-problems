#include<bits/stdc++.h>
using namespace std;

// Time complextiy :- O(N)
// Space complexity :- O(1)

// Approach :-   
// loop from 1 to n count the number of set bit in each number 

//Link :- https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

// Function to get no of set bits in binary
// representation of positive integer n
int setBits(int n) {
	int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

// Count total set bits in all 
// numbers from 1 to n
int countSetBits(int n)  {
   int res = 0;
   for (int i=1; i<=n; i++)
      res += setBits(i);
   return res;
}