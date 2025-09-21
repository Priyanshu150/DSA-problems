#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(len(n))
// Space complexity :- O(N)

// Approach :-  
// We can use 3 different data structure for the different function 
// this will help us optimized the time complexity of the queries and serve faster 
// for seraching, we can maintain a ds which stores movie -> {price, shop} mapping 
// so that we can easily query movies and return the top 5 result 
// For Drop and rent, we can use movie -> {shop, price} mapping 
// where we find the info for shop and movie information provided in the function 
// and delete it from the available movies and add into rented movie category
// Vice-versa is true for rent 
// In Report, we maintain 1 more ds for rented movies which is sorted in terms of {price, shop, movie}
// we fetch first 5 records of this and return it as a result 

// links :- https://leetcode.com/problems/design-movie-rental-system/

class MovieRentingSystem {
private:
    typedef pair<int,int> pii;

    unordered_map<int, set<pii> > available;    // movie -> {price, shop}
    unordered_map<int, set<pii> > movieToShop; // movie -> {shop, price}
    set<tuple<int,int,int>> rented;           // {price, shop, movie}

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // Store each entry into the respective data structure 
        for(auto &entry: entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            available[movie].insert({price, shop});
            movieToShop[movie].insert({shop, price});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int count = 0;
        
        // Check if the movie is present or not 
        if(available.count(movie)){
            // Pick the top 5 cheapest movie from the shop 
            for(auto [_, shop] : available[movie]){ // O(5)
                res.push_back(shop);
                count++;

                if(count >= 5)
                    break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        // Find the movie in moveToShop using binary search 
        auto it = movieToShop[movie].lower_bound({shop, INT_MIN}); // O(log(N))
        int price = it -> second;
        
        // delete the moive from avaialble ds 
        available[movie].erase({price, shop}); // O(log(N))
        // add the movie in rented ds 
        rented.insert({price, shop, movie}); // O(log(N))
    }
    
    void drop(int shop, int movie) {
        // Find the movie in moveToShop using binary search 
        auto it = movieToShop[movie].lower_bound({shop, INT_MIN}); // O(log(N))
        int price = it -> second;
        
        // add the movie in the rented ds
        available[movie].insert({price, shop}); // O(log(N))
        // delete the movie from the rented ds
        rented.erase({price, shop, movie}); // O(log(N))
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = 0;

        // check for the cheapest 5 rented movie 
        for(auto &[price, shop, movie]: rented){  // O(5)
            ans.push_back({shop, movie});
            count++;

            if(count >= 5)
                break;
        }
        return ans;
    }
};