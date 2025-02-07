#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        permutation(curr, res, nums, used);
        return res;
    }

    void permutation(vector<int>& curr, vector<vector<int>>& res, vector<int>& nums, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // Skip if already used

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            curr.push_back(nums[i]);
            used[i] = true;
            permutation(curr, res, nums, used);
            used[i] = false;  // Backtrack
            curr.pop_back();
        }
    }
};
