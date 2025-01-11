class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int minlenwindow = INT_MAX;
        int currsum=0;
        int high=0;
        int low=0;
        while(high<nums.size())
        {
            currsum+=nums[high];
            high++;

            while(currsum>=target)
            {
                int currwindowsize=high-low;

                minlenwindow=min(minlenwindow,currwindowsize);
                currsum-=nums[low];
                low++;
            }
        }
        return minlenwindow == INT_MAX?0 :minlenwindow;
    }
};