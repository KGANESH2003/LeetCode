class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<right)
        {
            mid=(left+right)/2;
            if(mid<right&&nums[mid]>nums[mid+1])
            {
                return nums[mid+1];
            }else if(mid>left&&nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            else if(nums[mid]<nums[right])
            {
                right=mid-1;
            }else{
                left=mid+1;
            }
        }return nums[left];
    }
};