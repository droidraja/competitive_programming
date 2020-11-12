class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        sort(heights.begin(),heights.end());
        int n = (int) heights.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(sortedHeights[i]!=heights[i]) {
                ans++;
            }
        }
        return ans;
    }
};