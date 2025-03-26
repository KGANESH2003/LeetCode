class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum = 0, counter = 0;  // Moved counter outside loop

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                counter++;  // Count consecutive 1s
                maximum = max(maximum, counter);  // Update maximum count
            } else {
                counter = 0;  // Reset count when encountering 0
            }
        }

        return maximum;
    }
};
