class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2; // Prevent overflow
            
            // Check if the mid element is the target
            if (nums[mid] == target) {
                return mid;
            }

            // Determine which half is sorted
            if (nums[i] <= nums[mid]) { // Left half is sorted
                if (nums[i] <= target && target < nums[mid]) {
                    j = mid - 1; // Target is in the left half
                } else {
                    i = mid + 1; // Target is in the right half
                }
            } else { // Right half is sorted
                if (nums[mid] < target && target <= nums[j]) {
                    i = mid + 1; // Target is in the right half
                } else {
                    j = mid - 1; // Target is in the left half
                }
            }
        }

        return -1; // Target not found
    }
};
