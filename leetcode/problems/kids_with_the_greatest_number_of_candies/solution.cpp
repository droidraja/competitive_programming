class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for(int candy:candies) {
            if(candy>max) {
                max = candy;
            }
        }
        vector<bool> isMax;
        for(int candy:candies) {
            if(candy+extraCandies>=max) {
                isMax.push_back(true);
            } else {
                isMax.push_back(false);
            }
        }
        return isMax;
    }
};