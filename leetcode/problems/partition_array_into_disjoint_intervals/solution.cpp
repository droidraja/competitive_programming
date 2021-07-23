class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        int big[n];
        int small[n];
        small[n-1] = nums[n-1];
        big[0] = nums[0];
        for(int i=1;i<n;i++) {
            big[i] = max(nums[i],big[i-1]);
            cout<<big[i]<<" ";
        }
        
        cout<<endl;
        for(int i=n-2;i>=0;i--) {
            small[i] = min(nums[i],small[i+1]);
        }
        
        for(int i=0;i<n-1;i++) {
            cout<<small[i]<<" ";
            if(big[i]<=small[i+1]) {
                return i+1;
            }
        }
        return 1;
        
    }
};