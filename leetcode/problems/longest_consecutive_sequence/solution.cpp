class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longestSequence  = 0;
        for(auto n:nums) {
            if(s.find(n-1)==s.end()) {
                //start of the series
                int sequenceLength = 0;
                int iter = n;
                while(s.find(iter)!=s.end()) {
                    iter++;
                    sequenceLength++;
                }
                longestSequence = (longestSequence<sequenceLength)?sequenceLength:longestSequence;
            }
        }
        return longestSequence;
    }
};