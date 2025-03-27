class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // To track the minimum price encountered so far
        int maxProfit = 0;      // To track the maximum profit

        for(int i=0;i<prices.size();i++)
        {
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        

        return maxProfit;
    }
};
