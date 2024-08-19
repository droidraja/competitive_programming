class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);

        
        for(int i=0;i<nums.size();i++) {
            int j = nums.size()-i-1;
            if(i==0) {
                leftProduct[i] = nums[i];
                rightProduct[j] = nums[j];
                continue;
            }
            
            leftProduct[i] = leftProduct[i-1]* nums[i];
            rightProduct[j] = rightProduct[j+1] * nums[j];
            cout<<i<<" "<<leftProduct[i]<<" "<<endl;
        }
        
        vector<int> results;
        results.push_back(rightProduct[1]);
        
        for(int i=1;i<nums.size()-1;i++) {
            results.push_back(leftProduct[i-1]*rightProduct[i+1]);
        }
        results.push_back(leftProduct[nums.size()-2]);
        return results;
    }
};