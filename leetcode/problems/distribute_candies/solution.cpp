class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_set<int> ss;
        int n = candyType.size();
        for(int CT:candyType) {
            ss.insert(CT);
        }
        return (n/2<ss.size())?n/2:ss.size();
    }
};