class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size()<k) return result;
        
        int i=0;
        int j=0;
        
        for(int i=0;i+k-1<nums.size();i++) {
            int current=0;
            int consecutive = 1;
            for(int j=i;j<i+k;j++) {
                if(j==i) {
                    current = nums[j];
                    continue;
                }
                if(nums[j]-1!=current) {
                    consecutive=0;
                    break;
                }
                current = nums[j];                
            }
            if(consecutive) {
                result.push_back(current);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};