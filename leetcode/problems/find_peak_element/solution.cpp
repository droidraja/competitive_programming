class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int max = INT_MIN;
        int max_index = -1;
        for(int i=0;i<nums.size();i++) {
            auto num = nums[i];
            if(max<=num) {
                max = num;
                max_index = i; 
            }
        }
        return max_index;
    }
};