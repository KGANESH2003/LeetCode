#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res, int index) {
        if (target == 0) {
            res.push_back(curr);  // Found a valid combination
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;  // No point in continuing if the number exceeds the target

            curr.push_back(candidates[i]);  // Choose the current number
            dfs(candidates, target - candidates[i], curr, res, i + 1);  // Move to the next index
            curr.pop_back();  // Backtrack to try other combinations
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates easily
        vector<vector<int>> res;
        vector<int> curr;
        dfs(candidates, target, curr, res, 0);
        return res;
    }
};
