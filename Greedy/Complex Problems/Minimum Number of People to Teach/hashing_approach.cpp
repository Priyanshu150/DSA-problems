#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n )
// Space Complexity: O(1)

// Approach :- 
// For each friend check if they can communicate among themselves or not 
// if they cannot put them into hash set 
// for searching into language for each pair of friends 
// we can make the knowBase of language in terms of hash set so searching becomes easy
// At last check in the hash set of people who can't communicate that 
// which is the most frequenct language spoken among themselves 
// final answer will be number_of_people_in_set - most_common_language_spoken

// Link :- https://leetcode.com/problems/minimum-number-of-people-to-teach/

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> knownLang(m);

        // Build language knowledge set 
        for(int i=0; i<m; ++i){
            for(auto lang: languages[i]){
                knownLang[i].insert(lang);
            }
        }
        unordered_set<int> needTeachings;

        // Find all the people who need to be taught
        for(auto frnds: friendships){
            int u = frnds[0] - 1;
            int v = frnds[1] - 1;
            bool canCommunicate = false;

            for(auto lang: knownLang[u]){
                if(knownLang[v].count(lang)){
                    canCommunicate = true;
                    break;
                }
            }
            if(!canCommunicate){
                needTeachings.insert(u);
                needTeachings.insert(v);
            }
        }
        vector<int> count(n+1, 0);
        int maxCommon = 0;

        // mostCommon language speaken among all the peoples 
        for(int person: needTeachings){
            for(int lang: knownLang[person]){
                count[lang] += 1;
                maxCommon = max(count[lang], maxCommon);
            }
        }
        return needTeachings.size() - maxCommon;
    }
};