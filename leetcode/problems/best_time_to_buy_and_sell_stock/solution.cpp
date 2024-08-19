class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        
        int maxProfit = 0;
        vector<int> mins;
        mins.push_back(prices[0]);
        for(int i=1;i<prices.size();i++) {
            mins.push_back(min(mins[i-1],prices[i]));
        }
        
        for(int i=prices.size()-1;i>0;i--) {
            if(prices[i]-mins[i-1]>maxProfit) {
                maxProfit = prices[i]-mins[i-1];
            }
        }
        return maxProfit;
    }
};