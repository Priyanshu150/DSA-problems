#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(log(N))
//Space complexity :- O(1)    

//Approach :-
// Compare the number of bit in both the numbers 
// If bit are same, then x = num1 ,because same number has XOR value equal to zero
// If num1 has more bits than num2, Intial x = num1 and traverse from right to left in x and reset the set bit
// If num2 has more bits than num1, Intial x = num1 and traverse from right to left in x and set the un-set bit
// Repeat both the operation for diff num of time
// Where diff is the difference of the bits b/w num1 and nums2

//link :- https://leetcode.com/problems/minimize-xor/description/

class Solution {
private:
    int setBitCont(int num){
        int cnt = 0;
        while(num > 0){
            num &= (num-1);
            cnt++;
        }
        return cnt;
    }

    int isSetBit(int num, int pos){
        return num & (1<<pos);
    }

    void setBit(int &num, int pos, int value){
        int offSet = 1<<pos;
        if(value){
            num |= offSet;
        }
        else{
            offSet = ~offSet;
            num &= offSet;
        }
    }

public:
    int minimizeXor(int num1, int num2) {
        int setBitOfnum1 = setBitCont(num1), setBitOfnum2 = setBitCont(num2);
        int x = num1, diff = setBitOfnum2 - setBitOfnum1;

        if(diff == 0)
            return x;
        else if(diff > 0){
            for(int i=0; i<32 && diff>0; ++i){
                if(!isSetBit(x, i)){
                    setBit(x, i, 1);
                    diff--;
                }
            }
        }
        else{
            for(int i=0; i<32 && diff<0; ++i){
                if(isSetBit(x, i)){
                    setBit(x, i, 0);
                    diff++;
                }
            }
        }
        return x;
    }
};