class Solution {
public:
    int reverse(int x) {
        int reversenum = 0;
        while (x != 0) {
            int lastdigit = x % 10;
            x /= 10;

            // Check for overflow before updating reversenum
            if (reversenum > INT_MAX / 10 || (reversenum == INT_MAX / 10 && lastdigit > 7)) return 0;
            if (reversenum < INT_MIN / 10 || (reversenum == INT_MIN / 10 && lastdigit < -8)) return 0;

            reversenum = (reversenum * 10) + lastdigit;
        }
        return reversenum;
    }
};
