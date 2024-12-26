class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0; // To track the number of valid elements
        int i = 0; // Pointer to place the next valid element
        
        for(int j = 0; j < nums.size(); j++) {
            // Only add an element if it has appeared less than or equal to twice
            if(i < 2 || nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
                count++;
            }
        }

        return count;
    }
};
