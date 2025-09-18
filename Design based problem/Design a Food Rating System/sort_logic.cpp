#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N)
// Space complexity :- O(N)

// Approach :-  
// we'll use unordered_map to keep track of each mapping 
// one for foodRating, one for food to cuisine mapping and other for cusine -> {rating, food}
// {rating, food} store them in set so that sorted version of it get stored 
// intead of rating store -rating so that we'll get the higest rated food in front of the set 

// FoodRatings -> In constructor we store each of them in mentioned format
// changeRating -> In this function using previous rating delete the last record of cusine -> {-prevRating, food}
//              and then update the new rating in the repective map and all the other ds
// highestRate -> check the cusine -> {-rating, food} ds and  the first one will have highest rating 
//              return the food name for that 

// links :- https://leetcode.com/problems/design-a-food-rating-system/

class FoodRatings {
private:
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, set<pair<int,string>>> cuisineRating;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i=0; i<n; ++i){
            foodRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodRating[food];

        // remove the previous cusine's food rating 
        cuisineRating[cuisine].erase({-oldRating, food});
        // add new cusine's food rating 
        cuisineRating[cuisine].insert({-newRating, food});

        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineRating[cuisine].begin() -> second;
    }
};