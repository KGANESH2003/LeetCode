#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& curr, int i, vector<vector<int>>& res, vector<int>& arr, int sum, int target) {
        if (sum == target) {
            res.push_back(curr);  // If sum matches target, add to result
            return;
        } else if (sum > target) {
            return;  // If sum exceeds target, no need to proceed
        }

        for (int j = i; j < arr.size(); j++) {
            curr.push_back(arr[j]);  // Add current element to the combination
            dfs(curr, j, res, arr, sum + arr[j], target);  // Recursive call with updated sum
            curr.pop_back();  // Backtrack to explore other combinations
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;  // To store final combinations
        vector<int> curr;         // Current combination being built
        dfs(curr, 0, res, arr, 0, target);  // Start DFS from index 0 with sum 0
        return res;
    }
};
