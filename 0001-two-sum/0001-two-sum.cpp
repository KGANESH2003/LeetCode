class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int targetSum) {
        unordered_map<int, int> indexMap; // Map to store each number and its index
        for (int currentIndex = 0; currentIndex < numbers.size(); ++currentIndex) {
            int requiredNumber = targetSum - numbers[currentIndex];
            if (indexMap.find(requiredNumber) != indexMap.end()) {
                return {indexMap[requiredNumber], currentIndex}; // Return indices if pair is found
            }
            indexMap[numbers[currentIndex]] = currentIndex; // Store the current number and its index
        }
        return {}; // Return empty if no pair is found
    }
};
