class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefixSum;
        
        int previous = 0;
        
        for(auto num:nums) {
            prefixSum.push_back(previous+num);
            previous = previous+num;
        }
        return prefixSum;
    }
};