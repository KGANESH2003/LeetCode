class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> intcount;

        // Count frequency of each number
        for(int num : nums) {
            intcount[num]++;
        }

        // Find the majority element
        for(int num : nums) {
            if(intcount[num] > nums.size() / 2) {
                return num;  // Return the majority element
            }
        }
        
        // This return is just a placeholder; the problem guarantees a majority element exists.
        return -1; 
    }
};
