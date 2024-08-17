class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        vector<int> result;
        if(nums.size()<k) return result;
        
        int i=0;
        int j=0;
        
        
        while(i+k-1<nums.size()) {
            while(j-i+1<k && i+k-1<nums.size()){
                if(nums[j+1]-1!=nums[j]) {
                    //i has to become j
                    //and push -1 for each i till it becomes j
                    if(i+k==nums.size()){
                        result.push_back(-1);
                        break;
                    } 
                    
                    for(int l=i;l<j+1;l++) result.push_back(-1);
                    
                    i=j+1;
                    j=i;
                } else {
                    j++;
                }
            }
            if(j-i+1==k)
                result.push_back(nums[j]);
            i++;
        }
        while(result.size()!=nums.size()-k+1) result.pop_back();
        
        return result;
    }
};