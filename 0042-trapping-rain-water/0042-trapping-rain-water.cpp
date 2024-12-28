class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = 0, rightmax = 0, total = 0;
        int n = height.size();
        int i = 0, j = n - 1;

        while (i <= j) {
            if (height[i] <= height[j]) {
                if (height[i] < leftmax) {
                    total += leftmax - height[i];
                } else {
                    leftmax = height[i];
                }
                i++;
            } else {
                if (height[j] < rightmax) {
                    total += rightmax - height[j];
                } else {
                    rightmax = height[j];
                }
                j--;
            }
        }
        return total;
    }
};
