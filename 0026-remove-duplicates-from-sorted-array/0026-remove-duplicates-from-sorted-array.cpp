class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector<int>res;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            if(res.empty()||res.back()!=nums[i])
            {
                res.push_back(nums[i]);
                count++;
            }
        }

        for(int i=0;i<res.size();i++)
        {
            nums[i]=res[i];
        }return count;
    }
};