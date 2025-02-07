#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);  // Add the current subset to the result

    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates
        if (i > index && nums[i] == nums[i - 1]) continue;

        current.push_back(nums[i]);  // Include nums[i] in current subset
        generateSubsets(nums, i + 1, current, result);  // Recursive call with next index
        current.pop_back();  // Backtrack to remove the last element
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end());  // Sort to bring duplicates together
    generateSubsets(nums, 0, current, result);
    return result;
}

};