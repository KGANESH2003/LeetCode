#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        permutation(curr, res, nums);
        return res;
    }

    void permutation(vector<int>& curr, vector<vector<int>>& res, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (find(curr.begin(), curr.end(), nums[i]) == curr.end()) {
                curr.push_back(nums[i]);
                permutation(curr, res, nums);
                curr.pop_back();
            }
        }
    }
};
