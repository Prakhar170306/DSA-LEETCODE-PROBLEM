class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> bestBuy(n);
        bestBuy[0] = prices[0];

        for (int pos = 1; pos < n; pos++) {
            bestBuy[pos] = min(bestBuy[pos - 1], prices[pos - 1]);
        }

        int maxProfit = 0;

        for (int pos = 1; pos < n; pos++) {
            int currentProfit = prices[pos] - bestBuy[pos];
            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
};