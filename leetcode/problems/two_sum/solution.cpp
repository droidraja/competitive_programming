class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> last_seen;

        for(int i=0;i<nums.size();i++) {
            if(last_seen.find(target-nums[i])!=last_seen.end()) {
                return {last_seen[target-nums[i]],i};
            } else {
                last_seen[nums[i]] = i;
            }
        }
        return {};
    }
};