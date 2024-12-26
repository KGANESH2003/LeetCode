class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int firstmin=min(prices[0],prices[1]);
        int secondmin=max(prices[0],prices[1]);

        for(int i=2;i<prices.size();i++)
        {
            if(prices[i]<firstmin)
            {
                secondmin=firstmin;
                firstmin=prices[i];
            }else if(prices[i]<secondmin)
            {
                secondmin=prices[i];
            }
        }

        if(money-(firstmin+secondmin)>=0)
        {
            return money-(firstmin+secondmin);
        }else{
            return money;
        }
    }
};