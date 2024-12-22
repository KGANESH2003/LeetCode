class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> charcount;

        // Count occurrences of each number
        for (int num : nums) {
            charcount[num]++;
        }

        // Find and return the number that appears only once
        for (int num : nums) {
            if (charcount[num] == 1) {
                return num;
            }
        }

        return -1; // This line should never be reached
    }
};
