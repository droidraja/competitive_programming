class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        
        int alice = 0;
        int bob = 0;

        for(auto &n:nums) {
            if(n<10) alice+=n; else bob+=n;
        }
        return alice!=bob;
    }
};