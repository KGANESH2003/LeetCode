class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>intcount;
        for(int num:nums)
        {
            intcount[num]++;
        }
        for(int num:nums)
        {
            if(intcount[num]>nums.size()/2)
            {
                return num;
            }
        }return -1;
        
    }
};