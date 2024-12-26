class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>res;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                res.push_back(nums[i]);
                count++;
            }
        }
        for(int i=0;i<res.size();i++)
        {
            nums[i]=res[i];
        }
        return count;
    }
};