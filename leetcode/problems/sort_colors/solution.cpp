class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int left=0;
        int right=nums.size()-1;
        for(int i=0;i<right+1;) {
            cout<<i<<endl;
            if(nums[i]==2) {
                int temp = nums[i];
                nums[i] = nums[right];
                nums[right]=temp;
                right--;
            } else if(nums[i]==0) {
                int temp=nums[i];
                nums[i]=nums[left];
                nums[left]=temp;
                i++;
                left++;
            } else {
                i++;
            }
        } 
    }
};