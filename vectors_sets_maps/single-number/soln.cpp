class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> cnt_map;
        
        for(auto num:nums) {
            cnt_map[num]++;
        }
        
        for(auto cnt:cnt_map) {
            if(cnt.second==1) {
                return cnt.first;
            }
        }
        return 0;
    }
};
