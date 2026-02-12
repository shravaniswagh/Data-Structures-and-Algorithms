class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =  prices.size();
        int lowest = INT_MAX;
        int profit =0;
        for(int i=0;i<n;i++){
            lowest = min(lowest, prices[i]);
            profit = max(profit, prices[i]-lowest);
        }
        return profit;
    }
};