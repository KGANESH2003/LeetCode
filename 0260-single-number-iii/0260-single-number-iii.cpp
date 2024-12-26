class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int>res;
        unordered_map<int,int>intcount;
        for(int num:nums)
        {
            intcount[num]++;
        }

        for(int num:nums)
        {
            if(intcount[num]==1)
            {
                res.push_back(num);
            }
        }return res;
    }
};