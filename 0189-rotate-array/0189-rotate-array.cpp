class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k>nums.size())
        {
            k=k-nums.size();
        }
        int left=0,right=nums.size()-k;
        vector<int>res;

        for(int i=0;i<nums.size();i++)
        {
            if(right<=nums.size()-1)
            {
                res.push_back(nums[right++]);
            }else{
                res.push_back(nums[left++]);
            }
        }nums= res;
    }
};