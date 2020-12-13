class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> encountered;
        
        for(auto num:nums) {
            if(encountered.find(num)==encountered.end()) {
                encountered.insert(num);
            } else {
                return true;    
            }
        }
        return false;
    }
};