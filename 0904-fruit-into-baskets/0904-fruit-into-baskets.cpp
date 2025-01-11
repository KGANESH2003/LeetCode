class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>basket;
        int left=0;
        int right=0;
        int maxfruits=0;
        while(right<fruits.size())
        {
            basket[fruits[right]]++;
            if(basket.size()>2)
            {
                while(basket.size()>2)
                {
                    basket[fruits[left]]--;
                    if(basket[fruits[left]]==0)
                    {
                        basket.erase(fruits[left]);
                    }left++;
                }
            }
            if(basket.size()<=2)
            {
                maxfruits=max(maxfruits,right-left+1);
            }right++;
        }return maxfruits;
        
    }
};