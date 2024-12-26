class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // To track the minimum price encountered so far
        int maxProfit = 0;      // To track the maximum profit

        for (int price : prices) {
            minPrice = min(minPrice, price);  // Update the minimum price
            maxProfit = max(maxProfit, price - minPrice);  // Update the maximum profit
        }

        return maxProfit;
    }
};
