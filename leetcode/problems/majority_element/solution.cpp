class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maj_cnt=1;
        int ele=nums[0];

        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=ele)
            {
                maj_cnt-=1;
            } else {
                maj_cnt+=1;
            }
            if(maj_cnt==0) {
                maj_cnt=1;
                ele=nums[i];
            }
         }
         return ele;
    }
};