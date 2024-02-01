// LC DCC 2023/12/17
// 2353. Design a Food Rating System
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

// // Approach 1:
// class Food {
// public:
//     // Store the food's rating.
//     int foodRating;
//     // Store the food's name.
//     string foodName;

//     Food(int foodRating, string foodName) {
//         this->foodRating = foodRating;
//         this->foodName = foodName;
//     }

//     // Overload the less than operator for comparison
//     bool operator<(const Food& other) const {
//         // If food ratings are same sort on the basis of their name
//         if(foodRating == other.foodRating)
//             return foodName > other.foodName;
//         // Sort on the basis of food rating
//         return foodRating < other.foodRating;
//     }
// };

// class FoodRatings {
//     // Map food with its rating.
//     unordered_map<string, int> foodRatingMap;
//     // Map food with cuisine it belongs to.
//     unordered_map<string, string> foodCuisineMap;
    
//     // Store all food of a cusine in priority queue (to sort them on ratings/name)
//     // Priority queue element -> Food: (foodRating, foodName)
//     unordered_map<string, priority_queue<Food>> cuisineFoodMap;

// public:
//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//         for(int i = 0; i < foods.size(); ++i) {
//             // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
//             foodRatingMap[foods[i]] = ratings[i];
//             foodCuisineMap[foods[i]] = cuisines[i];
//             // Insert the '(rating, name)' element in current cuisine's priority queue.
//             cuisineFoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
//         }
//     } 
    
//     void changeRating(string food, int newRating) {
//         // Update food's rating in 'foodRating' map.
//         foodRatingMap[food] = newRating;
//         // Insert the '(new rating, name)' element in respective cuisine's priority queue.
//         auto cuisineName = foodCuisineMap[food];
//         cuisineFoodMap[cuisineName].push(Food(newRating, food));
//     }
    
//     string highestRated(string cuisine) {
//         // Get the highest rated 'food' of 'cuisine'.
//         auto highestRated = cuisineFoodMap[cuisine].top();
        
//         // If latest rating of 'food' doesn't match with 'rating' on which it was sorted in priority queue,
//         // then we discard this element of the priority queue.
//         while(foodRatingMap[highestRated.foodName] != highestRated.foodRating) {
//             cuisineFoodMap[cuisine].pop();
//             highestRated = cuisineFoodMap[cuisine].top();
//         }
        
//         return highestRated.foodName;
//     }
// };

// Approach 2:
class FoodRatings {
    map<string, pair<string, int>> foodToCuisineAndRating;
    map<string, map<int, set<string>>> cuisineToRatingAndFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            foodToCuisineAndRating[foods[i]] = {cuisines[i], ratings[i]};
            cuisineToRatingAndFoods[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        auto foodInfo = foodToCuisineAndRating.find(food);
        string cuisine = foodInfo->second.first;
        int oldRating = foodInfo->second.second;
        foodInfo->second.second = newRating;

        cuisineToRatingAndFoods[cuisine][oldRating].erase(food);
        if(cuisineToRatingAndFoods[cuisine][oldRating].empty())
            cuisineToRatingAndFoods[cuisine].erase(oldRating);

        cuisineToRatingAndFoods[cuisine][newRating].insert(food);
    }

    string highestRated(string cuisine) {
        return *cuisineToRatingAndFoods[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
*/

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:

Sample Output:

*/