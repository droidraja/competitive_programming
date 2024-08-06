class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long product = 1;
        int zeroes = 0;
        for(auto num: nums) {
            if(num!=0) {
                product *= num;
            } else {
                zeroes+=1;
            }
            
        }
        vector<int> result;
        for(auto num:nums) {
            if(num==0 && zeroes==1) {
                result.push_back(product);
            } else if(zeroes>=1){
                result.push_back(0);
            } else {
                result.push_back(((int)(product/num)));
            }
            
        }
        return result;
    }};