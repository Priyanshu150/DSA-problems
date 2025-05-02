#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n)  
// Space complexity :- O(1)

// Approach :-
// maintain the last in of left and right pushed domionoes while traversing the string 
// if the current_index is a left pushed, then check which is present on the left side of it 
// if it's left then b/w them all should be marked as 'L' (left push dominoes)
// if it's right then equal force should be applied until they cross each other or meet at same point (double push dominoes)
// if last_L position point to -1, then b/w them mark all as 'L' (left push dominoes)
// other wise if current_index is right, then check which if present on the left side 
// if it's left then ignore it as they both exerts force in different directions
// if it's right then make all b/w them as 'R' denoting right force is applied on them (right push dominoes)
// if we're at n position and left side of it is right then mark them as 'R' denoting right force should be applied (right push dominoes)

// Link :- https://leetcode.com/problems/push-dominoes/

class Domino{
  public:
    void doubleDeominoPush(int last_R, int pos, string &dominoes){
        while(last_R < pos){
            dominoes[last_R++] = 'R';
            dominoes[pos++] = 'L';
        }
    }

    void leftDominoPush(int start, int end, string &dominoes){
        while(start <= end)
            dominoes[start++] = 'L';
    }

    void rightDominoPush(int start, int end, string &dominoes){
        while(start <= end)
            dominoes[start++] = 'R';
    }
};

class Solution {
public:
    string pushDominoes(string dominoes) {
        Domino newDomino;
        int n = dominoes.size(), last_L = -1, last_R = -1;

        for(int i=0; i<n; ++i){
            if(dominoes[i] == 'L'){
                if(last_R > last_L){
                    newDomino.doubleDeominoPush(last_R, i, dominoes);
                }
                else if(last_L > last_R || last_L == -1){
                    newDomino.leftDominoPush(last_L+1, i, dominoes);
                }
                last_L = i;
            }
            else if(dominoes[i] == 'R'){
                if(last_R > last_L){
                    newDomino.rightDominoPush(last_R, i, dominoes);
                }
                last_R = i;
            }
        }
        if(last_R > last_L){
            newDomino.rightDominoPush(last_R, n-1, dominoes);
        }
        return dominoes;
    }
};