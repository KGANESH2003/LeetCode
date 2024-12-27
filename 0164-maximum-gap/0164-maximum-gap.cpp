class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<=1)
        {
            return 0;
        }
        int i=0,j=i+1,maxgap=0;
        while(j<n)
        {
            if(nums[j]>nums[i])
            {
                maxgap=max(maxgap,nums[j]-nums[i]);
            }
            i++;
            j++;
        }return maxgap;
    }
};