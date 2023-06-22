class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if(prices.size()<=1) return 0;

    int min_so_far = prices[0];
    int max_profit = 0;
    int n = prices.size();

    for(int i=1;i<n;i++) {
        
        max_profit = max(max_profit,prices[i]-min_so_far);
        min_so_far = min(min_so_far,prices[i]);
    }


        return max_profit;
    }
};