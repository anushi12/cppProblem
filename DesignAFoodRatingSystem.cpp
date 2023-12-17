class FoodRatings {
public:
    struct comp{
        bool operator()(const pair<int, string>& l, const pair<int, string>& r) const{
            if(l.first != r.first) return l.first> r.first;
            else return l.second < r.second;
        }
    };

    unordered_map<string, set<pair<int,string>, comp>> cuisineToFood;
    unordered_map<string, int>rate;
    unordered_map<string, string>foodToCuisine;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i<foods.size();i++){
            cuisineToFood[cuisines[i]].insert({ratings[i],foods[i]});

            foodToCuisine.insert({foods[i],cuisines[i]});

            rate.insert({foods[i],ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = foodToCuisine[food];
        int r = rate[food];
        rate[food] = newRating;
        cuisineToFood[c].erase({r, food});
        cuisineToFood[c].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        pair<int,string> p = *(cuisineToFood[cuisine].begin());
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
