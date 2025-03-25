class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // Count the number of decreases
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) { // Check decreasing points
                count++;
            }
            if (count > 1) return false; // More than one decrease is invalid
        }
        return true;
    }
};
