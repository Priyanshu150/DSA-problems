import java.util.*;

//Time complexity :- O(n*n)
//Space complexity :- O(n)

// Approach :-
// find the count of zeros from last element of each row until we hit the end or we found 1
// store the information in an array
// for each row, check how many zeros is need 
// then peek on the array and find the number the first element greater or equal to need 
// swap the count and move it to the current possition 
// repeat this until complete array is sorted 


// Link :- https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length; // rows == columns
        // endZeros[i] = count of consecutive 0s from the end of ith row
        int[] endZeros = new int[n];

        for (int i = 0; i < n; i++) {
            int j = n - 1; // start from end

            int count = 0;
            // count the number of zeros 
            while (j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }

            endZeros[i] = count;
        }

        int steps = 0;

        for (int i = 0; i < n; i++) {
            // every row need 
            int need = n-i-1;

            int j = i;
            // find the first number which has need cnt 
            while (j < n && endZeros[j] < need) {
                j++;
            }
            // if the need cnt doesn't exist then it's not possible 
            if (j == n) {
                return -1;
            }
            // count the number of swaps needed to achieve this 
            steps += (j - i);
            // swap the value until need count comes to row 
            while (j > i) {
                int temp = endZeros[j];
                endZeros[j] = endZeros[j - 1];
                endZeros[j - 1] = temp;
                j--;
            }
        }

        return steps;
    }
}