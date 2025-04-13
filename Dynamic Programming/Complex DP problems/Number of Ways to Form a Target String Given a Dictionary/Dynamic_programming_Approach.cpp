#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    #define ll long long

    int dp[1001][1001];
    int mod = 1e9+7;
    vector<vector<int>> char_freq;
    int target_size, word_size, n;

    int countWays(vector<string>& words, int ind, string &target, int tpos){
        if(tpos == target_size)
            return (ind <= word_size);
        
        if(ind == word_size || (word_size - ind < target_size - tpos))
            return 0;
        
        if(dp[ind][tpos] != -1)
            return dp[ind][tpos];
        
        char curr = target[tpos];
        ll notTake = countWays(words, ind+1, target, tpos);
        ll take = countWays(words, ind+1, target, tpos+1)%mod;
        ll total_ways = (notTake + (ll)char_freq[ind][curr-'a']*take)%mod;

        return dp[ind][tpos] = total_ways;
    }

public:
    int numWays(vector<string>& words, string target) {
        target_size = target.size();
        n = words.size();
        word_size = words[0].size();
        char_freq = vector<vector<int>> (word_size, vector<int> (26, 0));

        for(int i=0; i<n; ++i){
            for(int j=0; j<word_size; ++j){
                char curr = words[i][j];
                char_freq[j][curr - 'a'] += 1;
            }
        }
        memset(dp, -1, sizeof(dp));
        return countWays(words, 0, target, 0);
    }
};