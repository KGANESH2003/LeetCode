class Solution {
public:
    double average(vector<int>& salary) {
        double avg = 0, sum = 0; // Use double for avg and sum
        int n1 = INT_MAX, m = INT_MIN;
        int n = salary.size();
        for (int i = 0; i < n; i++) {
            n1 = min(n1, salary[i]);
            m = max(m, salary[i]);
            sum += salary[i];
        }
        avg = (sum - n1 - m) / (n - 2); // Perform division as double
        return avg;
    }
};
