class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;

        // Copy only the valid elements from nums1
        for (int i = 0; i < m; i++) {
            res.push_back(nums1[i]);
        }

        // Copy all elements from nums2
        for (int j = 0; j < n; j++) {
            res.push_back(nums2[j]);
        }

        // Sort the merged array
        sort(res.begin(), res.end());

        // Copy the sorted elements back to nums1
        for (int i = 0; i < res.size(); i++) {
            nums1[i] = res[i];
        }
    }
};
