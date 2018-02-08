class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // apply to fee to either buy or sell
        int buy = INT_MIN, sell = 0;
        for (auto p:prices)
        {
            buy = max(buy, sell - p - fee);
            sell = max(sell, buy +p);
        }
        return sell;
    }
};
