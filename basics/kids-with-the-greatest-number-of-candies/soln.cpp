class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
     
        vector<bool> result;
        
        //Find the kid with max candies before distribution
        int currentMax = 0;
        for(auto candy:candies) {
            if(candy>currentMax) currentMax=candy;    
        }
        
        //For each kid check if all the extra candies are given to him, will he become the kid with the largest number of candies or match the existing kid with largest candies
        for(auto candy:candies) {
            if(candy+extraCandies>=currentMax) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};
