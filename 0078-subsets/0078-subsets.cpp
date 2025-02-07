class Solution {
public:
    void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);  // Add the current subset to the result
    
    // Loop through remaining elements to build subsets in lexicographical order
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);           // Include nums[i] in current subset
        generateSubsets(nums, i + 1, current, result);  // Recursive call with next index
        current.pop_back();                   // Backtrack to remove the last element
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end());  // Sort to ensure lexicographical order
    generateSubsets(nums, 0, current, result);
    return result;
}
};