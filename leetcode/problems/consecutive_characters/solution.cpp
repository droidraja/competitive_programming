class Solution {
public:
    int maxPower(string s) {
        
        if(s.size()<=1) {
            return s.size();
        }
        int n = (int) s.size();
        int currentAns = 1;
        int ans = 1;
        for(int i=1;i<n;i++) {
            if(s[i]==s[i-1]) {
                currentAns++;
                ans = max(ans,currentAns);
            } else {
                currentAns=1;
            }
        }
        
        return ans;
    }
};