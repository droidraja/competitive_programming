class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> cnt_map;
        for(auto num:nums) {
            cnt_map[num]++;
        }
        int pairs = 0;
        
        // choose 2 from cnt, hence it is NC2 = n!/((n-2)!*2!) = (n*(n-1))/2
        for(auto entry:cnt_map) {
            int cnt = entry.second;
            pairs +=  (cnt*(cnt-1))/2;
        }
        
        return pairs;
    }
};