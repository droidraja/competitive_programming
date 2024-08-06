class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return 0;
        int max = 0;

        int next_max = 0;
        int steps=0;
        for(int i=0;i<n;i++) {
            if(i+nums[i]>next_max) {
                next_max=i+nums[i];
                cout<<next_max<<endl;
            }
            if(max==i) {
                max=next_max;
                steps++;
                if(next_max>=n-1) return steps;
            }
            
        }
        return steps;
    }
};