#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array
        
        long long left = 0, right = 0, total = 0, maxFreq = 0;

        while (right < nums.size()) {
            total += nums[right]; // Add the new element to the total sum
            
            // If the window is invalid (we can't make all elements nums[right])
            while ((right - left + 1) * nums[right] - total > k) {
                total -= nums[left]; // Remove the leftmost element from the total
                left++; // Shrink the window from the left
            }
            
            // Update max frequency
            maxFreq = max(maxFreq, right - left + 1);
            
            right++; // Expand the window
        }
        
        return maxFreq;
    }
};
