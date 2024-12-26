class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int>intcount;

        for(int num:nums)
        {
            intcount[num]++;
        }

        for(int num:nums)
        {
            if(intcount[num]>1)
            {
                return true;
            }
        }return false;
    }
};