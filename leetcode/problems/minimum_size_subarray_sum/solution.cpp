class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        

        int left=0;
        int right=0;
        int sum=nums[0];
        int minLength = INT_MAX;
        while(true) {
            if(sum<target){
                if(right+1<nums.size()) {
                    right+=1;
                    sum+=nums[right];
                } else {
                    break;
                }

            } else {
                cout<<"left"<<left<<"right"<<right<<endl;
                minLength = min(minLength,right-left+1);
                if(minLength==1) break;
                if(left==right && left+1<nums.size()) {
                        left=left+1;
                        right=right+1;
                        sum=nums[left];
                } else if(left<right) {
                    sum-=nums[left];
                    left+=1;
                } else {
                    break;
                }
            }
        }
        if(minLength!=INT_MAX) return minLength; else return 0;

    }
};