class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //store the last seen index of each number
        unordered_map<int,int> encountered;

        for(int i=0;i<nums.size();i++) {
            if(encountered.find(nums[i])!=encountered.end()){
                if(i-encountered[nums[i]] <= k) return true;
            }
            encountered[nums[i]] = i;
        }
        return false;
    }
};