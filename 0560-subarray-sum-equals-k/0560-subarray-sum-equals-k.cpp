class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int count=0,prefix=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            int remove=prefix-k;
            count+=mpp[remove];
            mpp[prefix]+=1;
        }return count;
    }
};