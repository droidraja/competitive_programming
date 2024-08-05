class Solution {
public:
    bool canJump(vector<int>& nums) {

        int max= nums[0];
        for(int i=1;i<nums.size();i++) {
            if(max>=nums.size()-1) return true;
            if(max<i) return false;
            if(i+nums[i]>max) max = i+nums[i];
        }
        return true;    
    }
};